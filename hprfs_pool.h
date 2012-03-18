//
//  hprfs_pool.h
//
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//
//  @brief This file defines the interface of pool_t, pool_t instance is a
//  singletone instance to manage all pools inside, and provide access methods
//  to sectors and fat
//

#ifndef _hprfs_pool_h
#define _hprfs_pool_h
#include <pthread.h>
#include "hprfs_basic_class.h"
#include "hprfs_layout.h"

/*
 * max number of slaver pools 
 */
#define POOL_MAX_POOL_NUM            8

/* the master pool id, a master pool contains a fat section and sectors section
 * |header|fat|sectors|
 */
#define POOL_ID_MASTER               0xdadadada

/* the slaver pool id, a slaver pool contains only sectors section
 * |header|sectors|
 */
#define POOL_ID_SLAVER               0xbabababa

/*
 * pool data structure
 * this structure defines a data structure of pool
 * sevral pool is addressed in a different bank by a start
 * address 'bankAddr', uplayer like sector access the pool via
 * a virtual address which was composed by a bank address and an
 * offset, for example:
 * 0x100003000, means the pool which has the '0x10000000' start address
 * offset the physical address with 0x3000 based on the physical 'pPoolPhysical',
 *  that is (pPoolPhysical + 0x3000)
 */
typedef struct{
    uint32_t       id;                // pool identifier
    uint32_t       bankAddr;          // bank address of this pool
    void          *pPoolPhysical;     // pool physical address 
    void           fatSize;           // file allocation table size
    uint32_t       poolSize;          // pool physical size
    uint32_t       initialized;       // whether pool data has been initialized
    uint32_t       totalSectors;      // total sectors in this pool
}pool_data_t;

/*
 * pool structure
 * a pool contains at least one master pool data structure
 * and many slaver pools, it provides the fundermental functionalities
 * for hprfs
 */
typedef struct{
    INHERIT_BASIC_CLASS;

    pool_data_t        pools[POOL_MAX_POOL_NUM];
    pthread_mutex_t      mutex;
}pool_t;

/*
 * @brief this funciton create and return a pool instance
 * @param piPool [out] an instance of pool_t
 * @returns errorCodes
 *    SUCCESS instance created successfully
 *    ENOMEM  no memory
 */
int pool_create(pool_t **piPool);

/*
 * @brief this function reads contents from a logic pool address
 *        0x10005000 -> a pool with a startAddr = 0x10000000
 *                   -> offset 0x5000
 *  so, physical address = (pool->pPool + 0x5000) 
 * @param iPool [in]  instance of class pool_t
 * @param addr  [in]  pool logic address to read
 * @param pBuf  [out] buffer address to fill data
 * @param size  [in]  buffer size to fill
 * @returns errorCodes
 *       SUCCESS     pool read successful
 *       EBADPARAM   bad parameters
 *       ENORESOURCE no pool reourse founded
 *       ELIMIT      read size has exceeds the limitation
 */
int pool_read(pool_t *iPool,void *addr, void *pBuf, uint32_t size);
 
/*
 * @brief this function writes contents to a logic pool address
 * @param iPool [in] instance of class pool_t
 * @param addr  [in] pool logic address to write
 * @param pBuf  [in] buffer address to write
 * @param size  [in] size to wirte
 * @returns errorCodes
 *       SUCCESS     pool write successful
 *       EBADPARAM   bad parameters
 *       ENORESOURCE no pool resource for that logic address 
 *       ELIMIT      write size has exceeds the limitation
 */
int pool_write(pool_t *iPool, void *addr, void *pBuf,
 uint32_t size);

/*
 * @brief this function adds a pool, it is neccesary
 * to be called at least once
 *
 * @param iPool [in] an instance of pool_t
 * @param aPool [in] a memory pool
 * @param size  [in] size of memory pool
 * @returns errorCodes
 *      SUCCESS   pool added successfully
 *      EBADPARAM bad parameters
 *      ELIMIT    pool number has met the max limitation
 *      E2BIG     pool size is too big
 */
int pool_add_pool(pool_t *iPool, void *aPool, uint32_t size);

 /*
 * @brief this function caculate the total pool size
 *
 * @param iPool instance of pool_t class
 * @param poolSize out put poolSize
 * @returns errorCodes
 *      SUCCESS   pool size caculated successfully
 *      EBADPARAM bad parameters
 */
int pool_caculate(pool_t *iPool, uint32_t *poolSize);

 /*
 * @brief this function enumerates the first sub pool insides pool mgr
 * @param iPool instance of pool_t class
 * @param ppPool   return an instance of pool_t
 * @returns errorCodes
 *      SUCCESS   pool size caculated successfully
 *      EBADPARAM bad parameters
 *      ENORESOURCE  no pool resource founded
 */
int pool_get_first(pool_t *iPool, pool_data_t **ppPool);

 /*
 * @brief this function enumerates next sub pool insides pool mgr
 * @param iPool instance of pool_t class
 * @param ppPool   return an instance of pool_t
 * @returns errorCodes
 *      SUCCESS   pool size caculated successfully
 *      EBADPARAM bad parameters
 *      ENORESOURCE  no pool resource founded
 */
int pool_get_next(pool_t *iPool, pool_data_t **ppPool);
#endif

