#include"binaryTree1.h"
#include<stdio.h>
#include"binarySearchTree2.h"


//트리 초기화
void TreeInit(BTree * root){	
		root=NULL;
}

//노드에 저장된 데이터 반환
Data GetNodeData(BTree * tree){

	return GetData(tree);
}

//데이터 저장
void Insert(BTree * root, Data data){

	BTree * parent=NULL;
	BTree * child=root;

	BTree * newNode=MakeTreeNode();
	SetData(newNode, data);
	
	if(NULL != root){
		printf("root != NULL\n");
		//while문을 통해 새 노드가 삽입될 위치를 찾는다.
		while(NULL != child){	
			//값이 중복된 경우.
			if(data == GetData(child)){
				return;
			}

			parent=child;

			if(GetData(parent) > data){
				child=GetLeftSub(parent);
			}else {
				child=GetRightSub(parent);
			}
		} //while
		//while문의 탈출 조건이 child == NULL 이므로
		//현재 parent의 위치가 새 노드가 삽입될 위치의 부모노드

		//부모 노드와의 값 비교에 따라
		//왼쪽인지 오른쪽인지 위치 결정함.
		if(GetData(parent) > data){
			SetLeftSub(parent, newNode);
		}else {
			SetRightSub(parent, newNode);
		}

	} else {
		printf("root == NULL\n");
		root=newNode;
	}
	
}

//데이터 탐색
BTree * Search(BTree * tree, Data target){

	BTree * cur=tree;
	Data curData;
	

	while(NULL != cur){
		
		curData=GetData(cur);

		//탐색 성공
		if(curData == target){
			return cur;
		}else if(curData > target) {
			cur=GetLeftSub(cur);
		}else {
			cur=GetRightSub(cur);
		}
	} //while
	
	return NULL;
}
