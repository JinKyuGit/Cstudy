#include<stdlib.h>
#include"deque1.h"



//초기화
void DequeInit(Deque * deque){
	
	deque->head=NULL;
	deque->tail=NULL;
	deque->numOfData=0;

}

//비었는지 확인
int IsEmpty(Deque * deque){

	if(deque->numOfData == 0){
		return 0;
	}else {
		return 1;
	}

}

//head에 데이터 추가 > head변경.
void AddHead(Deque * deque, Data data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	//첫 삽입인 경우와 아닌 경우
	if(NULL == deque->head){
		deque->head=newNode;
		deque->tail=newNode;
	} else {
		newNode->next=deque->head;
		deque->head->prev=newNode;
		deque->head=newNode;
	}

	(deque->numOfData)++;
}

//tail에 데이터 추가 > tail변경
void AddTail(Deque * deque, Data data){
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	if(NULL == deque->tail){	
		deque->head=newNode;
		deque->tail=newNode;
	} else {
		newNode->prev=deque->tail;
		deque->tail->next=newNode;
		deque->tail=newNode;
	}

	(deque->numOfData)++;
}

//head 데이터 꺼내기 - IsEmpty() 선행되어야함.
Data RemoveHead(Deque * deque){
	
	Node * Rnode=deque->head;
	Data data=deque->head->data;

	//head 변경
	deque->head=deque->head->next;
	
	free(Rnode);
	(deque->numOfData)--;

	return data;
}

//tail 데이터 꺼내기
Data RemoveTail(Deque * deque){

	Node * Rnode=deque->tail;
	Data data=deque->tail->data;

	//head 변경
	deque->tail=deque->tail->prev;
	
	free(Rnode);
	(deque->numOfData)--;

	return data;
}
