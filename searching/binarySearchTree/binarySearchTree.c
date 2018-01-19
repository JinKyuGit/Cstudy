#include<stdio.h>
#include<stdlib.h>
#include"binarySearchTree.h"

//기존 트리 함수.
//트리 노드 생성해서 반환.
Tree * MakeTreeNode(){

	Tree * newNode=(Tree *)malloc(sizeof(Tree));
	newNode->left=NULL;
	newNode->right=NULL;

	return newNode;
}

void SetData(Tree * tree, Data data){
	
	tree->data=data;
}

Data GetData(Tree * tree){
	
	return tree->data;
}

void SetLeftSub(Tree * pTree, Tree * cTree){
	
	if(NULL != pTree->left){
		free(pTree->left);
	}
	pTree->left=cTree;
}

void SetRightSub(Tree * pTree, Tree * cTree){
	
	if(NULL != pTree->right){
		free(pTree->right);
	}
	pTree->right=cTree;
}

Tree * GetLeftSub(Tree * pTree){
	return pTree->left;
}

Tree * GetRightSub(Tree * pTree){
	return pTree->right;
}

void ChangeLeftSub(Tree * pTree, Tree * cTree){
	pTree->left=cTree;
}

void ChangeRightSub(Tree * pTree, Tree * cTree){
	pTree->right=cTree;
}

Tree * RemoveLeftSub(Tree * pTree){
	
	Tree * delNode=pTree->left;
	pTree->left=NULL;

	return delNode;
}

Tree * RemoveRightSub(Tree * pTree){

	Tree * delNode=pTree->right;
	pTree->right=NULL;

	return delNode;
}

//중위 순회
void LeftTraverse(Tree * root, Func func){
	
	if(NULL == root){
		return;
	}
		
	LeftTraverse(GetLeftSub(root), func);
	func(root->data);
	LeftTraverse(GetRightSub(root), func);

}

//이진탐색 트리 함수.
void BTreeInit(Tree ** tree){
	*tree=NULL;
}

//데이터 삽입.
void InsertData(Tree ** tree, Data data){
	
	Tree * newNode=MakeTreeNode();
	SetData(newNode, data);
	
	Tree * parent=NULL;
	Tree * child=*tree; //우선 루트대입.

		while(NULL != child){
			if(child->data == data){
				printf("키 값이 중복됩니다.\n");
				return;
			}

			parent=child;
			
			if(data < GetData(parent)){
				child=GetLeftSub(parent);
			}else {
				child=GetRightSub(parent);
			}
		} //while
		
		//새 삽입이 루트노드가 아닌 경우.
		if(NULL != parent){
			if(data < GetData(parent)){
				SetLeftSub(parent, newNode);
			}else {
				SetRightSub(parent, newNode);
			}
		//루트 노드인 경우
		}else {
			*tree=newNode;
		}
}

//데이터 탐색.
Tree * SearchData(Tree * tree, Data target){

	Tree * cur=tree;
	Data data;
	while(NULL != cur){
		
		data=cur->data;

		if(target == data){
			return cur;
		} else if(target < GetData(cur)){
			cur=GetLeftSub(cur);
		} else {
			cur=GetRightSub(cur);
		}
	}
	//while문이 깨졌다는 것은
	//탐색 실패를 의미함.
		return NULL;
}

//데이터삭제
//1. 루트인 경우와 아닌 경우
//2. 단말 노드인 경우
//3. 자식 노드가 1개인 경우
//4. 자식 노드가 2개인 경우.
//4의 경우 대체값 - 왼쪽 서브트리 중 가장 큰 값이나
//오른쪽 서브트리 중 가장 작은 값.
//5. 없는 경우.
Tree * DeleteData(Tree ** tree, Data target){
	
	Tree * tempRoot=MakeTreeNode();
	ChangeRightSub(tempRoot, *tree);

	Tree * parent;
	Tree * child=*tree;
	Tree * delNode;

	//값의 탐색.
	while(NULL != child && target != GetData(child)){

		parent=child;

		if(target < GetData(parent)){
			child=GetLeftSub(parent);
		}else {
			child=GetRightSub(parent);
		}
	} //while
	
	//탐색에 실패한 경우.
	if(NULL == child){
		return NULL;
	}
	
	delNode=child;
	
	//대체 과정.
	//삭제할 노드가 단말노드인 경우.
	if(NULL == GetLeftSub(delNode) && 
				NULL == GetRightSub(delNode)){
		if(GetLeftSub(parent) == delNode){
			RemoveLeftSub(parent);
		}else {
			RemoveRightSub(parent);
		}
	//하나의 자식이 있는 경우.
	} else if(NULL == GetLeftSub(delNode) ||
				NULL == GetRightSub(delNode)){
		Tree * temp;
		
		//임시 포인터로 삭제될 노드의 자식 노드 가리킴.
		if(NULL != GetLeftSub(delNode)){
			temp=GetLeftSub(delNode);
		}else {
			temp=GetRightSub(delNode);
		}
		//부모 노드의 자식 노드 중
		//삭제될 노드가 있던 자리를 채움.
		if(GetLeftSub(parent) == delNode){
			ChangeLeftSub(parent, temp);
		}else {
			ChangeRightSub(parent, temp);
		}
	//자식노드가 2개인 경우.
	//대체 노드의 탐색과정 필요
	//대체 노드는 -> 오른쪽 서브트리의 가장 작은 값.
	//이 경우 삭제될 위치의 노드의 값을
	//대체 노드의 값으로 변경한 후, 대체노드를 삭제함.
	} else {
		Tree * cTemp=GetRightSub(delNode);
		Tree * pTemp=delNode;
		Data delData;
		
		//대체 값 탐색.
		while(NULL != GetLeftSub(cTemp)){
			pTemp=cTemp;
			cTemp=GetLeftSub(pTemp);
		} //while
 		//반복문 종료 시점 - cTemp가 대체노드 가리킴.

		delData=GetData(delNode);
		SetData(delNode, GetData(cTemp));
		
		//만약 대체할 노드가 자식노드를 가진경우
		//(이 경우는 오른쪽 노드를 가진 경우밖에 없다.)
		//대체할 노드의 부모의 왼쪽 또는 오른쪽에
		//해당 자식 노드를 연결함.
		if(NULL != GetRightSub(cTemp)){
			if(cTemp == GetLeftSub(pTemp)){
				ChangeLeftSub(pTemp, GetRightSub(cTemp));
			}else {	
				ChangeRightSub(pTemp, GetRightSub(cTemp));
			}
		}

		delNode=cTemp;
		SetData(delNode, delData);
	} //else
	
	//함수 초기에 root노드를 임시 루트 노드의
	//오른쪽에 연결하였으나, 위의 과정 중에
	//root노드가 변했다는 것은
	//루트 노드가 삭제 대상이라는 의미.
	if(*tree != GetRightSub(tempRoot)){
		*tree=GetRightSub(tempRoot);
	}

	free(tempRoot);
	return delNode;
}
