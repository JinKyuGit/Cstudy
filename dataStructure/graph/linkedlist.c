#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"

//리스트 초기화
void ListInit(List * list){
	
	list->head=NULL;
	list->cur=NULL;
	list->before=NULL;
	list->numOfData=0;
}

//데이터 삽입 
void LInsert(List * list, Data data){

	Node * newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;

	(list->numOfData)++;

	// 첫 삽입인 경우.
	if(NULL == list->head){
		list->head=newNode;
	//첫 삽입이 아닌 경우.
	//데이터 추가 방향 -> head에 추가.
	}else {
		//만약 head->next가 존재하는 경우.
		if(NULL != list->head->next){
			newNode->next=list->head->next;
		}

		list->head->next=newNode;
	} //else
}

//데이터 조회
Node * LFirst(List * list){

	if(NULL == list->head){
		return NULL;
	}

	list->cur=list->head;
	list->before=list->head;
	return list->cur;
}

Node * LNext(List * list){

	if(NULL == list->cur){
		return NULL;
	}
	
	list->before=list->cur;

	if(NULL != list->cur->next){
		list->cur=list->cur->next;
	}else {
		list->cur=NULL;
	}

	return list->cur;
}

//cur가 가리키는 데이터 반환.
Data LRemove(List * list){

	Data del=list->cur->data;
	//비어진 자리를 연결.
	list->before->next=list->cur->next;
	list->cur=list->before;
	
	return del;
}

