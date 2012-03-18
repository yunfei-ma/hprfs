//
//  hprfs_sector.h
//
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//
//  This file defines interface of sector which is introduced
//  to divide pools into small pieces and manage them, a sector's
//  size can be arbitrary, a file cluster contains at least one sector
//

#ifndef _hprfs_sector_h
#define _hprfs_sector_h
#include "hprfs_basic_class.h"
#include "hprfs_pool.h"
#include "hprfs_binary_tree.h"

/*
 * a sector is now allocated for a file content
 */
#define SECTOR_CONTENT_MAGIC             0xeeedbeef

/*
 * a sector is freed
 */
#define SECTOR_FREE_MAGIC               0xaccabaab

/* sector header type
 * sector is used to store contents of a file, a sector can connect with another
 * sector to construct a cluster via 'nextID'.
 */
typedef struct{
    uint32_t  magic;          // magic number
    uint32_t  index;          // current index
    uint32_t  nextAddr;       // next connected index
    uint32_t  sectorSize;     // sector size
}sector_header_t;

typedef struct {
    sector_header_t header;      // sector header
    uint32_t        addr;        // a logical pool address
}sector_data_t;

/* sector instance variables */
typedef struct{
    INHERIT_BASIC_CLASS;
    pool_t   *iPool;
    binary_tree_t  *freeSectors;
}sector_t;

/*
 * @brief This function creates an instance of sector_t
 *
 * @param iSector   a new created instance of sector_t
 *
 * @returns error_codes_t
 *     SUCCESS         instance created successfully
 *
 */
int sector_create(sector_t **piSector);

/*
 * @brief set an instance of pool_t to a sector_t instance, all operations
 *        of sector is based on an iPool instance
 *
 * @param iSector   an instance of sector_t
 * @param iPool     an instance of pool_t
 *
 * @returns error_codes_t
 *          SUCCESS     operation successful
 *          EINVAL      iSector is an invalid instance
 *          EBADPARAM   bad parameters
 */
int sector_set_pool(sector_t *iSector, pool_t *iPool);

/*
 * @brief load sectors from an instance of pool, 
 */
int sector_load_pool(sector_t *iSector, pool_t *iPool);

/*
 * @brief read a sector in a pool by index
 * 
 * @param iPool 
 */
int sector_read_by_index(pool_t *iPool, sector_header_t *pHeader,
						void *pContext,
                        uint32_t contextOffset,
						uint32_t contextSize
						);

int sector_write_by_index(pool_t *iPool, sector_header_t *pHeader
						void)
#endif
