/*
 * High Performance RAM File System
 * Copyright (c) 2012 by Ma Yunfei<yunfei.ma2@gmail.com>
 */ 
#ifndef _POOL_MGR_H_
#define _POOL_MGR_H_
#include "pool.h"
/*
 * pool structure
 * a pool contains at least one master pool data structure
 * and many slaver pools, it provides the fundermental functionalities
 * for hprfs
 */
typedef struct{
   pool_data_t  pools[HPRFS_POOL_MAX_POOL_NUM];
}pool_mgr_t;

int pool_mgr_create(pool_mgr_t **ppPoolMgr);


/*

 * @brief this function adds a pool, it is neccesary

 * to be called at least once

 * @param iPool [in] an instance of pool_t

 * @param aPool [in] a memory pool

 * @param size  [in] size of memory pool

 * @returns errorCodes

 *      SUCCESS   pool added successfully

 *      EBADPARAM bad parameters

 *      ELIMIT    pool number has met the max limitation

 *      E2BIG     pool size is too big

 */
int pool_mgr_add_pool(pool_mgr_t *iPoolMgr, void *aPool, uint32_t size);



 /*

 * @brief this function caculate the total pool size

 * @param iPool instance of pool_mgr class

 * @param poolSize out put poolSize

 * @returns errorCodes

 *      SUCCESS   pool size caculated successfully

 *      EBADPARAM bad parameters

 */
int pool_mgr_caculate(pool_mgr_t *iPoolMgr, uint32_t *poolSize);



#endif
