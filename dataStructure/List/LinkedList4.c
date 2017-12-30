#include <stdio.h>
#include <stdlib.h>
#include "LinkedList4.h"




//초기화
void ListInit(List * plist){

	plist->head=NULL;
	plist->cur=NULL;
	plist->numOfData=0;

}

//삽입 - head
void LInsert(List * plist, Data data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	//첫번째 삽입 -head
	//두번째 삽입 -head->next
	if(NULL == plist->head){
		newNode->next=newNode;
		newNode->prev=newNode;
		plist->head=newNode;
	} else {
		//newNode의 next > 기존 head의 next
		//기존 head->next->prev는 newNode
		//newNode->prev는 head
		//head->next 는 newNode
		newNode->next=plist->head->next;
		plist->head->next->prev=newNode;
		newNode->prev=plist->head;
		plist->head->next=newNode;
	}
	(plist->numOfData)++;
}
//head 노드 조회
Data LFirst(List * plist, Data * pdata){
	
	if(NULL == plist->head){
		printf("데이터가 없습니다.\n");
		return 0;
	}

	plist->cur=plist->head;
	*pdata=plist->cur->data;

	return 1;
}

//cur이동 >>
Data LNext(List * plist, Data * pdata){
	
	//데이터가 없는 경우. 삭제되는 경우.
	if(NULL == plist->head){
		return 0;
	}
	
	plist->cur=plist->cur->next;	
	*pdata=plist->cur->data;
	return 1;
}

//cur 이동 <<
Data LPrev(List * plist, Data * pdata){
	
	if(NULL == plist->head){
		return 0;
	}
	
	plist->cur=plist->cur->prev;
	//LNext와 비교해서 이 코드만 다르므로
	//하나의 함수로 묶어서 매개변수에 따라 분기할 수도 있음
	*pdata=plist->cur->data;
	return 1;
}

//노드 삭제
Data LRemove(List * plist, Data direct){

	//조회방향.
	// direct 0 > next
	// direct 1 > prev
	Node * Rnode=plist->cur;
	Data data=plist->cur->data;
	
	//삭제되는 노드가 헤드인 경우.
	//1. 마지막 노드인 경우
	//2. 마지막 노드가 아닌 경우
	if(Rnode == plist->head){
		if(NULL == plist->head->next){
			//이 경우 cur를 옮기는 의미가 없으므로
			//바로 함수 종료.
			plist->head=NULL;
			free(Rnode);
			(plist->numOfData)--;
			return data;
		} else {
			plist->head=plist->head->next;
		}
	
	} //if 

	//이전 노드의 next > 두칸 앞의 노드
	//다음 노드의 prev > 두칸 뒤의 노드
	plist->cur->prev->next=plist->cur->next;
	plist->cur->next->prev=plist->cur->prev;
	
	//조회 방향에 따른 cur의 이동 상이.
	if(direct == 0){
		plist->cur=plist->cur->prev;
	}else {
		plist->cur=plist->cur->next;
	}

	free(Rnode);
	(plist->numOfData)--;

	return data;
}


//데이터의 수 출력.
Data LCount(List * plist){
	return plist->numOfData;
}

