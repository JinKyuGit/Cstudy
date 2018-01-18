#include<stdio.h>
#include<stdlib.h>
#include"binaryTree1.h"
#include"binarySearchTree.h"


void PrintData(int data){
	printf("%d ", data);
}

void ShowAll(BTree * tree){
	LeftTraverse(tree, PrintData);
	printf("\n");
}



int main(){


	BTree  * root;
	
	TreeInit(&root);

	Insert(&root, 3);
	Insert(&root, 7);
	Insert(&root, 6);
	Insert(&root, 1);
	Insert(&root, 2);
	Insert(&root, 10);
	Insert(&root, 12);
	Insert(&root, 5);
	
	printf("%d\n", root->data);

	BTree * find=NULL;
	find=Search(root, 3);

	if(NULL == find){
		printf("탐색 실패.\n");
	}else {
		printf("탐색 성공.\n");
		printf("탐색 위치 : %p\n", find);
		printf("저장 값 : %d\n", find->data);
	}
	
	int del;
	
	while(NULL != root){
	ShowAll(root);
	printf("삭제할 데이터 : ");
	scanf("%d", &del);
	BTree * delNode=Delete(&root, del);
	if(NULL == delNode){
			printf("해당하는 데이터가 없습니다.\n");
	}else {
		printf("삭제된 데이터 : %d\n", delNode->data);
		free(delNode);
		}
	}
	return 0;
}
