#ifndef __BINARY_SEARCH_TREE_H__
#define __BINARY_SEARCH_TREE_H__

#include"binaryTree1.h"

void TreeInit(BTree * root);

Data GetNodeData(BTree * tree);

void Insert(BTree * root, Data data);

BTree * Search(BTree * tree, Data target);

#endif
