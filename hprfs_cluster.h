//
//  hprfs_cluster.h
//  
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//
//  This file defines interface to cluster_t, a cluster is to manage sectors of
//  a file, it is constructed at run time when a file is opened and changed
//  dynamically when applications do file operations
//

#ifndef _hprfs_cluster_h
#define _hprfs_cluster_h
#include "hprfs_basic_class.h"
#include "hprfs_layout.h"
#include "hprfs_binary_tree.h"

typedef struct {
    INHERIT_BASIC_CLASS;

    binary_tree_t *iClusterTree;      // a tree contains all sectors
    uint32_t       currentPosition;   // current read or write position
    uint32_t       totalSize;         // total size
    
}cluster_t;

#endif
