#include<stdlib.h>
#include"binaryTree1.h"
#include<stdio.h>

//트리 생성
BTree * MakeTreeNode(){

	BTree * tree=(BTree *)malloc(sizeof(BTree));
	tree->left=NULL;
	tree->right=NULL;

	return tree;
}

//트리의 데이터값 반환
Data GetData(BTree * tree){
	
	return tree->data;
}

//트리에 값 저장 - 트리의 생성은 main에서 담당
void SetData(BTree * tree, Data data){

	tree->data=data;
}

//트리의 왼쪽 트리 주소값 반환.
BTree * GetLeftSub(BTree * tree){

	return tree->left;
}

//트리의 오른쪽 트리 주소값 반환.
BTree * GetRightSub(BTree * tree){
	
	return tree->right;
}

//main 트리의 왼쪽에 sub 트리 연결
void SetLeftSub(BTree * main, BTree * sub){

	if(NULL != main->left){
		free(main->left);
	}

	main->left=sub;
}

//main 트리의 오른쪽에 sub 트리 연결
void SetRightSub(BTree * main, BTree * sub){

	if(NULL != main->right){
		free(main->right);
	}

	main->right=sub;
}

//순회
void LeftTraverse(BTree * tree, Func func){
	
	//탈출조건
	if(NULL == tree){
		return;
	}

	//아래 3 줄의 순서를 통해, 전위 후위 순회를 결정할 수 있다.
	//func -> left -> right 의 경우 전위
	//left -> right -> func 의 경우 후위
	LeftTraverse(tree->left, func);
	func(tree->data);
	LeftTraverse(tree->right, func);
	
	free(tree);
}
