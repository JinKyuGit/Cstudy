#include <stdio.h>
#include <stdlib.h>
#include "LinkedList2.h"

//초기화
void ListInit(List * plist){
	
	Node * dummy=(Node *)malloc(sizeof(Node));
	plist->head=dummy;
	plist->head->next=NULL;
	plist->numOfData=0;
	plist->comp=NULL; // 이후 메인에서 정렬기준 등록.
}
//노드의 추가
void LInsert(List * plist, LData data){
	
	if(NULL == plist->comp){
		FInsert(plist, data);
	}else {
		SInsert(plist, data);
	}
}

//정렬 기준이 없는 경우
void FInsert(List * plist, LData data){
	//초기화는 main에서 실시.

	Node * newNode=(Node*)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=plist->head->next;
	plist->head->next=newNode;
	(plist->numOfData)++;
}

//정렬 기준이 있는 경우.
void SInsert(List * plist, LData data){
	Node * newNode=(Node *)malloc(sizeof(Node));
	Node * search=plist->head;
	newNode->data=data;
	//첫 삽입인 경우 고려.
	while(1){
		if(NULL == search->next){
			//다음 노드가 없는 경우.
			break;
		}
		if(plist->comp(data, search->next->data)==0){
			//자리를 찾은 경우
			break;
		}
		search=search->next;
		//break될 때까지 한칸씩 이동.
	} //while
		newNode->next=search->next;
		search->next=newNode;
		(plist->numOfData)++;
}

//노드의 첫 데이터 조회
int LFirst(List * plist, LData * pdata){
	
	//데이터가 없는 경우.
	if(NULL == plist->head){ //NULL == plist->head->next
		printf("조회할 데이터가 존재하지 않습니다.\n");
		return 0;
	}

	plist->cur=plist->head->next;
	plist->before=plist->head;
	*pdata=plist->cur->data;
	return 1;
}

//노드의 다음 데이터 조회
int LNext(List * plist, LData * pdata){
	//더이상 데이터가 없는 경우
	if(NULL == plist->cur->next){
		printf("더이상 데이터가 없습니다.\n");
		return 0;
	}
	//before와 cur 한칸씩 이동
	plist->before=plist->cur;
	plist->cur=plist->cur->next;
	*pdata=plist->cur->data;
	return 1;

}

//데이터 삭제
LData LRemove(List * plist){
	
	Node * Rnode;
	LData data=plist->cur->data;
	//before의 next가 가리키는 위치는 cur->next 변경
	//cur는 뒤로 한칸 이동
	Rnode=plist->cur;
	plist->before->next=plist->cur->next;
	plist->cur=plist->before;
	free(Rnode);
	//이 경우 cur와 before가 모두 한 위치를 가리키게 되나
	//조회시 다시 cur가 앞서므로 상관 없음
	(plist->numOfData)--;

	return data;
}

// 데이터의 수 조회
int LCount(List * plist){
	return plist->numOfData;
}

//정렬 기준 - 메인에서 실행
void setSortRule(List * plist, int (*comp) (LData d1, LData d2)){
	plist->comp=comp;		
}

