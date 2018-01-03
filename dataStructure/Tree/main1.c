#include<stdio.h>
#include"binaryTree1.h"


void display(int a){
	
	printf("%d\n", a);
}

int main(){

	//A B C D 4개의 트리 생성
	//각각 값 넣고
	//B를 A의 왼쪽 서브트리로
	//C를 A의 오른쪽 서브트리로 연결.
	//D는 B의 왼쪽 서브트리.

	BTree * A=MakeTreeNode();
	BTree * B=MakeTreeNode();
	BTree * C=MakeTreeNode();
	BTree * D=MakeTreeNode();

	SetData(A, 1);
	SetData(B, 2);
	SetData(C, 3);
	SetData(D, 4);

	SetLeftSub(A, B);
	SetRightSub(A, C);
	SetLeftSub(B, D);

	//A를 통해 B C D 출력
	printf("B의 데이터 : %d\n", GetData(GetLeftSub(A)));
	printf("C의 데이터 : %d\n", GetData(GetRightSub(A)));
	printf("D의 데이터 : %d\n", 
			GetData(GetLeftSub(GetLeftSub(A))));

	LeftTraverse(A, display);

	return 0;
}
