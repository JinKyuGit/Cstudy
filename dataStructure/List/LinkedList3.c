#include<stdio.h>
#include<stdlib.h>
#include"LinkedList3.h"



//초기화
void ListInit(List * plist){
	
	plist->tail=NULL;
	plist->cur=NULL;
	plist->before=NULL;
	plist->numOfData=0;
}

//삽입 1 - tail에 추가
void LInsert1(List * plist, LData data){
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	(plist->numOfData)++;

	//첫 삽입인 경우
	if(NULL == plist->tail){
		plist->tail=newNode;
		plist->tail->next=newNode;
		//첫 삽입인 경우 tail == head
	
	//첫 삽입이 아닌 경우.
	} else {
		//1.newNode가 tail이 되므로, 기존 tail의 next정보 가져옴
		//2.기존 tail의 next는 newNode를 가리킴
		//3.tail 정보 변경
		newNode->next=plist->tail->next;
		plist->tail->next=newNode;
		plist->tail=newNode;
		//이 코드가 head삽입과의 유일한 차이점.
	}
}

//삽입 2 - head에 추가
void LInsert2(List * plist, LData data){
	
	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	(plist->numOfData)++;
	
	//첫 삽입.
	if(NULL == plist->tail){
		plist->tail=newNode;
		plist->tail->next=newNode;
	}else {
		newNode->next=plist->tail->next;
		plist->tail->next=newNode;
	}

}

//첫 데이터 조회 - head
LData LFirst(List * plist, LData * data){
	
	if(NULL == plist->tail){
		printf("데이터가 없습니다.");
		return 0;
	}
		
	plist->cur=plist->tail->next;
	plist->before=plist->tail;
	*data=plist->cur->data;
	return 1;
}

//첫 데이터 이후 조회
LData LNext(List * plist, LData * data){
	
	//삭제 고려.
	if(NULL == plist->tail){
		return 0;
		}
	//cur와 before가 한칸씩 이동.
	 plist->before=plist->cur;
	 plist->cur=plist->cur->next;
	 *data=plist->cur->data;

	 return 1;	
}

//현재위치 노드 삭제. 삭제한 데이터 반환.
LData LRemove(List * plist){
	
	Node * Rnode=plist->cur;
	LData data=plist->cur->data;

	//삭제하는 데이터가 tail인 경우
	//1. 데이터가 남아 있는 경우
	//2. 마지막 데이터인 경우.
	if(Rnode==plist->tail){
		if(plist->tail == plist->tail->next){	
			plist->tail=NULL;
			//tail을 NULL로 해야 LNext 중지.
		}else {
			plist->tail=plist->before;
		}
	}

	plist->before->next=plist->cur->next;
	plist->cur=plist->before;
	free(Rnode);
	(plist->numOfData)--;
	return data;

}
	
LData LCount(List * plist){
	return plist->numOfData;
}
