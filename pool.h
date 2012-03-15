/*
 * High Performance RAM File System
 * Copyright (c) 2012 by Ma Yunfei<yunfei.ma2@gmail.com>
 */
#ifndef _POOL_H_
#define _POOL_H_
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

/*
 * max number of slaver pools 
 */
#define POOL_MAX_POOL_NUM    8

/* the master pool id */
#define POOL_ID_MASTER               0xdadadada

/* the slaver pool id */
#define POOL_ID_SLAVER               0xbabababa

/* the max size of a pool as 256MB */
#define POOL_MAX_SIZE                0X10000000

/*
 * pool data structure
 * this structure defines a data structure of pool
 * sevral pool is addressed in a different position by a start
 * address 'startAddr', uplayer like sector access the pool via
 * a logical address which was composed by a startAddress and an
 * offset, for example:
 * 0x100003000, means the pool which has the '0x10000000' start address
 * offset the physical address with 0x3000 based on the physical 'pPool',
 *  that is (pPool + ox3000) 
 */
typedef struct{
   uint32_t       id;        // pool identifier
   uint32_t       startAddr; // start address of this pool
   void          *pPool;     // pool physical address 
   uint32_t       poolSize;  // pool physical size
   pthread_mutex_t    mutex;
   uint32_t       initialized;
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


#endif

