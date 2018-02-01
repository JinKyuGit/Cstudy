#include<stdio.h>
#include<stdlib.h>
#include"LinkedList.h"
#include"table.h"

//리스트 초기화
void ListInit(List * list, Comp comp){

	list->head=NULL;
	list->cur=NULL;
	list->before=NULL;
	list->numOfData=0;
	list->comp=comp;

}

//리스트에 값 넣기.
void LInsert(List * list, Slot * slot){

	Node * newNode=(Node *)malloc(sizeof(Slot));
	newNode->data=slot;
	newNode->next=NULL;
	(list->numOfData)++;

	//첫 삽입인 경우와 아닌경우 확인.
	if(NULL == list->head){
		list->head=newNode;
	}else {
		//비교 함수를 이용한 자리찾기.
		Node * cur=list->head;
		Node * before=NULL;
		//cur와의 비교 후 cur 앞에 넣을지 말지 결정.
		while(1){
			//비교할 cur가 업음. 즉 tail 도착.
			if(NULL == cur){
				break;
			}
			//cur보다 한칸 앞에 저장.
			if(list->comp(newNode, cur) == 0){
				break;
			}
			before=cur;
			cur=cur->next;
		} // while
		
		//break 사유에 따른 처리.
		if(NULL == cur){
			before->next=newNode;
		}else {
			newNode->next=cur;

			//before가 NULL일 수 있음.
			if(NULL != before){
				before->next=newNode;
			}
			//newNode가 head보다 앞에 오는 경우. 헤드변경.
			if(cur == list->head){
				list->head=newNode;
			}

		}
	} // else

}

//슬롯 반환. before는 NULL 상태.
Data LFirst(List * list){
	list->cur=head;
	return list->cur->data;
}

Data LNext(List * list){
	
	if(NULL == list->cur->next){
		return NULL;
	}
	list->before=cur;
	list->cur=list->cur->next;
	return list->cur->data;
}
//데이터 삭제. - 삭제할 슬롯 반환.
//데이터 유무여부는 해당 함수를 호출하는 곳에서 확인.
Data LRemove(List * list){
	
	Node * del=list->cur;
	
	if(list->head == list->cur){
		//이 경우 상관없음.
	}else {
		//끊어진 고리를 연결.
		list->before->next=list->cur->next;
		cur=before;
	}

	(list->numOfData)--;
	return del;
}
