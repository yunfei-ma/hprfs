//
//  hprfs_binary_tree.h
//  
//
//  Created by Yunfei Ma on 12-3-16.
//  Copyright (c) 2012 yunfei. All rights reserved.
//

#ifndef _hprfs_binary_tree_h
#define _hprfs_binary_tree_h
#include "hprfs_basic_class.h"

/*
 *  this struct defines a tree data to be managed
 *  by binary tree, a free function can be registered
 *  for free data automatically on removing data
 */
typedef struct {
    uint32_t          index;
    void              *data;
    free_function_t    free_func;
}tree_data_t;

/*
 * tree link structure
 */
typedef struct tree_node_t{
    vector_data_t data;
    struct tree_node_t *left;
    struct tree_node_t *right;
}tree_node_t;

/*
 * binary tree class data
 */
typedef struct{
    INHERIT_BASIC_CLASS;
    vector_link_t *root;
    uint32_t       minimal_index;
    uint32_t       maxmum_index;
    uint32_t       total;
}binary_tree_t;

/*
 * @brief create an instance of binary tree
 *
 * @param ppBinaryTree new binary tree instance created
 *
 * @returns error_codes_t
 *          SUCCESS     instance created successfully
 *          ENOMEM      no memory
 */
int binary_tree_create(binary_tree_t **piBinaryTree);

/*
 * @brief this function get the counts of data items in binary tree
 *
 * @param iBinaryTree an instance of binary_tree_t
 *
 * @returns error_codes_t
 *          SUCCESS     caculated successfully
 *          EBADPARAM   bad parameters
 */
int binary_tree_count(binary_tree_t *iBinaryTree, uint32_t *pCount);

/*
 * @brief this function searches the tree by index,
 *          and find out a data item
 *
 * @param iBinaryTree an instance of binary_tree_t
 *
 * @returns error_codes_t
 *          SUCCESS     data item founded successfully
 *          EBADPARAM   bad parameters
 *          ENORESOURCE no resource founded
 */
int binary_tree_find(binary_tree_t *iBinaryTree, uint32_t index,
                          void **ppData);

/*
 * @brief insert a data item with an index, note that 'index' no need to be
 *          unique or continue numbers, it is used by binary tree to arrange
 *          and search data in order
 *
 * @param iBinaryTree an instance of binary_tree_t
 * @param index       an number for binary tree to arrange and search
 * @param bInsertAfter FALSE insert before or TRUE after
 * @param pData       optional param set to NULL if not used,
 *                      data relative with that index
 * @param free_func   optional param set to NULL if not used, 
 *                      free function cresponding with 'pData', automatically
 *                      called when tree removes that data item.
 *
 * @returns error_codes_t
 *          SUCCESS     data item created and inserted to tree successfully
 *          EBADPARAM   bad parameters
 *          ENOMEM      failed to alloc memory for creating new data item node
 */
int binary_tree_insert(binary_tree_t *iBinaryTree, uint32_t index,
                       int  bInsertAfter,
                       void *pData /* optional */,
                       free_function_t free_func /* optional */);

/*
 * @brief remove a data itme with an index, if a free function was set
 *        previously, data is freed automatically
 *
 * @param iBinaryTree    an instance of binary_tree_t
 * @param index          an number for binary tree to search and remove
 *
 * @returns error_codes_t
 *          SUCCESS         data item removed from tree successfully
 *          EBADPARAM       bad parameters
 *          EOUTRANGE       index is outranged, less than minimal_index or larger
 *                          than maxmum_index
 *          ENORESOURCE     no such data item founded
 * 
 */
int binary_tree_remove(binary_tree_t *iBinaryTree, uint32_t index);

/*
 * @brief remove all data items and automatically free them if free function
 *          registerred
 *
 * @param iBinaryTree   an instance of binary_tree_t
 *
 * @returns error_codes_t
 *          SUCCESS     operations successful
 *          EBADPARAM   bad parameters
 *
 */
int binary_tree_remove_all(binary_tree_t *iBinaryTree);

/*
 * @brief this function will call the supplied traverse function for every node
 *        in the tree. The parameter 'param' and 'pData' in the node will be
 *        passed to the function to process.
 *
 * @param iBinaryTree      an instance of binary_tree_t
 * @param traverse_func    the callback function for each data item
 * @param param            will be transferred to traverse_func as the second
 *                          parameter
 *
 * @returns     error_codes_t
 *              SUCCESS     successful
 *              EBADPARAM   bad parameters
 */
int binary_tree_traverse(binary_tree_t *iBinaryTree,
                         callback_function_t traverse_func,
                         void       *param);

#ifdef _hprfs_binary_tree_c
/*
 * @brief this function will caculate the height for the tree, the height
 *        is the max number of comparations needs to be made when searching tree
 *        It also indecates how balence it is.
 *
 * @param iBinaryTree  an instance of binary tree
 * @param pHeight      return height value
 *
 * @returns     error_codes_t
 *              SUCCESS     successful
 *              EBADPARAM   bad parameters
 */
static int binary_tree_height(binary_tree_t *iBinaryTree, uint32_t *pHeight);

/*
 * @brief this function is called internally when tree needs to be balenced
 *
 * @param iBinaryTree   an instance of binary tree
 *
 * @returns     none
 */
static void binary_tree_balence(binary_tree_t *iBinaryTree);
#endif


#endif
