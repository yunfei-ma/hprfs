//
//  hprfs_layout.h
//
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//

#ifndef _hprfs_layout_h
#define _hprfs_layout_h

/* the max size of a pool as 256MB */
#define CFG_POOL_MAX_SIZE                0x10000000

/* each single pool size of the whole RAM FS 8MB */
#define CFG_POOL_SIZE                    0x1000000

/* File Allocation Table block size */
#define CFG_FAT_BLOCK_SIZE               (512 * 1024)

/*
 * Minimal size of a sector, configure this value smaller will get a better
 * utilization ratio, but too small may cause poor performance
 */
#define CFG_SECTOR_MINIMAL_SIZE          128


#endif
