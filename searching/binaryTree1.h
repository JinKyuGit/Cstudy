#ifndef __BINARYTREE1_H__
#define __BINARYTREE1_H__


typedef int Data;

typedef struct _btree {

	Data data;
	struct _btree * left;
	struct _btree * right;
	
} BTree;



BTree * MakeTreeNode();

Data GetData(BTree * tree);
void SetData(BTree * tree, Data data);

BTree * GetLeftSub(BTree * tree);
BTree * GetRightSub(BTree * tree);

void SetLeftSub(BTree * main, BTree * sub);
void SetRightSub(BTree * main, BTree * sub);

typedef void (*Func)(int a);

void LeftTraverse(BTree * tree, Func func);

void ChangeLeftSub(BTree * main, BTree * sub);
void ChangeRightSub(BTree * main, BTree * sub);

BTree * RemoveLeftSub(BTree * tree);
BTree * RemoveRightSub(BTree * tree);

#endif
