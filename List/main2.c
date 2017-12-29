#include <stdio.h>
#include "LinkedList2.h"

int sortInfo(LData d1, LData d2){
	if(d1<d2){
		//현재 오름차순 - 부등호 변경시 내림차순 가능.
		return 0;
	}else {
		return 1;
	}

}

int main(){

	//데이터 33 22 22 11 11 추가
	//출력
	//22 데이터 삭제
	//출력
	
	List list;
	LData data;

	ListInit(&list);
	setSortRule(&list, sortInfo);
		
	LInsert(&list, 33);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 11);
	LInsert(&list, 11);
		
	//출력
	printf("현재 데이터의 수 : %d\n", LCount(&list)); 
	
	if(LFirst(&list, &data)){
		printf("데이터 : %d\n", data);
			while(LNext(&list, &data)){
					printf("데이터 : %d\n", data);
				}//while
	}//if


	//22 데이터 삭제
	
	if(LFirst(&list, &data)){
			if(data==22){
				LRemove(&list);
			}
		
		while(LNext(&list, &data)){
				if(data==22){
					LRemove(&list);
				}

			} //while
	} //if

	//출력
	printf("현재 데이터의 수 : %d\n", LCount(&list)); 
	
	if(LFirst(&list, &data)){
		printf("데이터 : %d\n", data);
			while(LNext(&list, &data)){
					printf("데이터 : %d\n", data);
				}//while
	}//if



	return 0;
}	
