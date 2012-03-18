//
//  hprfs_types.h
//  
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//

#ifndef _hprfs_types_h
#define _hprfs_types_h
#include <stdio.h>
#include <stdlib.h>

/*
 * @brief error codes definitions
 */
typedef enum {
    SUCCESS,
    EBADPARAM,
    ENOMEM,
    EINVAL,
    ENORESOURCE,
    EFAILED,
    ENOTSUPORT,
    EBADSTATUS,
    EOUTRANGE,
    E2BIG,
    ERRORMAX
}error_codes_t;

/*
 * @brief free function type
 */
typedef void (*free_function_t)(void*);

/*
 * @brief callback function type
 */
typedef void (*callback_function_t)(void *pData, uint32_t param);

#endif
