#include<stdio.h>
#include<stdlib.h>
#include"stack2.h"


//스택 초기화
void StackInit(Stack * stack){

	stack->head=NULL;
	stack->numOfData=0;

}
//비었는지 확인 0 없음 1 있음
int IsEmpty(Stack * stack){

	if(NULL == stack->head){
		return 0;
	}else {
		return 1;
	}
}

//데이터 추가 - 새 데이터가 head가 됨.

void Push(Stack * stack, Data data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	(stack->numOfData)++;
	//첫 데이터인 경우와 아닌 경우 분리.
	if(NULL == stack->head){
		stack->head=newNode;
		stack->head->next=NULL;
		return;
	} else {
		newNode->next=stack->head;
		stack->head=newNode;
	}
}

//데이터 꺼내기 - 삭제
//head 변경
Data Pop(Stack * stack){
	
	Node * Pnode=stack->head; // 꺼내질 노드
	Data data=stack->head->data;
	stack->head=stack->head->next;
	
	free(Pnode);
	(stack->numOfData)--;

	return data;
}

//head 데이터 확인
Data Peek(Stack * stack){
	return stack->head->data;
}


