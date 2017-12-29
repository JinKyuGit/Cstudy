#include <stdio.h>
#include "ArrayList.h"

//초기화
void ListInit(List * plist){
	plist->numOfData=0;
	plist->cursor=-1;
}

//데이터 추가
void LInsert(List * plist, LData data){
	if(plist->numOfData>=100){
		printf("추가할 수 없습니다. : 용량 초과\n");
		return;
	}
	
	plist->arr[plist->numOfData]=data;
	(plist->numOfData)++;

}
//첫번째 데이터 참조
int LFirst(List * plist, LData * pdata){

	if(plist->numOfData==0){
		return 0;
	}
	plist->cursor=0;
	*pdata=plist->arr[plist->cursor];
	return 1;
}

//다음 데이터 조회
int LNext(List * plist, LData * pdata){
	if( (plist->cursor) >= ( (plist->numOfData)-1)){
		//커서의 값이 배열에 저장된 값의 수 -1 보다 커지면 false
		return 0;
	}

	(plist->cursor)++;
	*pdata=plist->arr[plist->cursor];
	return 1;
}

// 현재 커서값 삭제.
LData LRemove(List * plist){
	int i;
	LData rData=plist->arr[plist->cursor];
	
	for(i=(plist->cursor); i<(plist->numOfData)-1; i++){
		plist->arr[i]=plist->arr[i+1];
		//삭제된 데이터의 index를 기준으로 한칸씩 땡김.
	}
		(plist->numOfData)--;
		(plist->cursor)--;
		//제일 마지막 데이터가 삭제되는 경우 커서를 이동시켜야함.
		return rData;
		//삭제된 데이터 반환.
}

int LCount(List * plist){

	return plist->numOfData;
}
