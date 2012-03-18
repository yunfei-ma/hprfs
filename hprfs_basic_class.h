//
//  hprfs_basic_class.h
//  
//
//  Created by Yunfei Ma on 12-3-17.
//  Copyright (c) 2012年 yunfei. All rights reserved.
//
//
//  Basic class object provides functions to manage an instance's life time
//

#ifndef _hprfs_basic_class_h
#define _hprfs_basic_class_h
#include "hprfs_types.h"

typedef struct basic_class_t basic_class_t;

/* increase reference number of a class */
typedef void (*destroy_obj_t)(basic_class_t *iObj);

struct basic_class_t {
    uint32_t            ref_number;
    destroy_obj_t       destroy;
};

/* this macro is added in to the structure definition which class
 * want to inherit from basic class
 */
#define    INHERIT_BASIC_CLASS          basic_class_t   *iBasicObj

/*
 * @brief increase reference number of an exist object whic inheritant from
 *        basic_class_t, this function will enforce convert the instance to be
 *        a basic_class_t.
 *          
 *
 * @param any class that adopts to basic_class_t
 */

#define     ref_obj(iObj)       do{\
                if(NULL != iObj) {\
                    ((basic_class_t*)iObj)->ref_number ++;\
                }\
            }while(0)

/*
 * @brief unreference to an exist object which inherited basic_class_t.
 */
#define     unref_obj(iObj)     do{\
                    if(NULL != iObj) {\
                        if(0 == --((basic_class_t*)iObj)->ref_number){\
                            ((basic_class_t*)iObj)->destroy(iObj);\
                            iObj = NULL;\
                        }\
                }\
            }while(0)

/*
 * @brief create a basic object, any class can inheritance from an basic object
 *        via this function. A basic class provides functionalities of instance
 *        life time managements
 *
 * @param iObj              an instance of basic class object to be initialized,
 *                          must be non-null
 * @param destroy_func      a destroy function register to basic object to be
 *                          called when this instance needs to be destroied.
 */
static __inline int create_basic_object(basic_class_t *iObj,
                                            destroy_obj_t destroy_func)
{
    if ((NULL == iObj) || (NULL == destroy_func)) {
        return EBADPARAM;
    }
    
    iObj->ref_number = 1;
    iObj->destroy = destroy_func;
    return SUCCESS;
}
#endif
