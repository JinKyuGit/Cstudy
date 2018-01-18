#include<stdio.h>
#include"binaryTree1.h"
#include"binarySearchTree2.h"


int main(){


	BTree * root;
	printf("초기화\n");
	TreeInit(root);
	printf("root : %p\n", root);
	printf("삽입1\n");
	Insert(root, 3);
	printf("삽입2\n");
	Insert(root, 7);
	Insert(root, 6);
	Insert(root, 1);
	Insert(root, 2);
	Insert(root, 9);
	Insert(root, 8);
	
	printf("탐색\n");
	BTree * find=Search(root, 3);

	if(NULL == find){
		printf("탐색 실패.\n");
	}else {
		printf("탐색 성공.\n");
		printf("탐색 위치 : %p\n", find);
		printf("저장 값 : %d\n", find->data);
	}

	return 0;
}
