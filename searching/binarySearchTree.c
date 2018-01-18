#include"binaryTree1.h"
#include<stdio.h>
#include<stdlib.h>

//트리 초기화
void TreeInit(BTree ** root){	
		*root=NULL;
}

//노드에 저장된 데이터 반환
Data GetNodeData(BTree * tree){

	return GetData(tree);
}

//데이터 저장
void Insert(BTree ** root, Data data){

	BTree * parent=NULL;
	BTree * child=*root;

	BTree * newNode=MakeTreeNode();
	SetData(newNode, data);
	
	if(NULL != *root){
	//	printf(" root != NULL\n");
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
	//	printf(" root == NULL\n");
		*root=newNode;
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

//데이터 삭제
BTree * Delete(BTree ** root, Data data){
		
	BTree * tempRoot=MakeTreeNode();
	//임시 루트 노드	
	ChangeRightSub(tempRoot, *root);
	//임시 루트 노드의 오른족에 루트노드 연결.
	BTree * parent=tempRoot;
	//부모 노드 = 임시 루트
	BTree * child=*root;
	//자식 노드 = 원래 루트
	BTree * delNode;
	//삭제할 노드
	

	//우선 삭제할 값 탐색.
	
	while(NULL != child && GetData(child) != data){
		
		parent=child;
		
		if(data < GetData(parent)){
			child=GetLeftSub(parent);
		}else {
			child=GetRightSub(parent);
		}

	}//while
	
	//탐색 대상이 없는 경우.
	if(NULL == child){
		return NULL;
	}

	delNode=child;
	
	//이제 삭제할 노드의
	//자식의 갯수에 따른 (0, 1, 2) 조건 처리
	
	//첫번째 - 단말노드(자식노드 없음) 
	if(NULL == GetLeftSub(delNode) && 
			NULL == GetRightSub(delNode)){
		//부모 노드의 연결에서 제거.
		if(delNode == GetLeftSub(parent)){
			RemoveLeftSub(parent);
		}else {
			RemoveRightSub(parent);
		}
	
	//두번쩨 - 자식 노드가 하나인 경우
	} else if(NULL == GetLeftSub(delNode) ||
				NULL == GetRightSub(delNode)){
		BTree * temp;
		//삭제 대상의 자식노드를 가리킬 임시 노드.

		if(NULL != GetLeftSub(delNode)){
			temp=GetLeftSub(delNode);
		}else {
			temp=GetRightSub(delNode);
		}
		//삭제될 노드의 부모 노드의 자식노드를
		//삭제될 노드의 자식 노드로 연결.
		if(GetLeftSub(parent) == delNode){
			ChangeLeftSub(parent, temp);
		}else {
			ChangeRightSub(parent, temp);
		}
	
	//세번째 - 자식 노드가 둘 다 있는 경우.
	}else {
		BTree * temp=GetRightSub(delNode);
		BTree * tempParent=delNode;
		Data delData;
		//대체 노드 탐색
		//대체할 노드는 삭제 노드를 기준으로
		//오른쪽 서브 트리에서 가장 작은 값.
		while(NULL != GetLeftSub(temp)){
			tempParent=temp;
			temp=GetLeftSub(tempParent);
		} //while

		delData=GetData(delNode);
		//삭제할 노드의 값을 대체할 노드의 값으로 변경.
		SetData(delNode, GetData(temp));
		
		//대체 노드의 자식 노드 연결.
		//위의 코드에서 LeftSub가 NULL 이므로
		//오른쪽 서브를 연결.
		if(GetLeftSub(tempParent) == temp){
			ChangeLeftSub(tempParent, GetRightSub(temp));
		}else {	
			ChangeRightSub(tempParent, GetRightSub(temp));
		}
		
		delNode=temp;
		SetData(delNode, delData);
	} //else

	//삭제될 노드가 루트인 경우 처리
	if(*root != GetRightSub(tempRoot)){
		*root=GetRightSub(tempRoot);
	}
	free(tempRoot);
	return delNode;
}
