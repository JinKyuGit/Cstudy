#include <stdio.h>
#include "ArrayList.h"



int main(){

	//리스트 생성 데이터 5개 넣음 11 11 22 22 33
	//출력
	//2개 삭제 > 22
	//출력

	List list;
	int data;
	int Rdata;

	ListInit(&list);


	LInsert(&list, 11);
	LInsert(&list, 11);
	LInsert(&list, 22);
	LInsert(&list, 22);
	LInsert(&list, 33);

	//출력
	
	if(LFirst(&list, &data)){
		printf("%d ", data);

		while(LNext(&list, &data)){
				printf("%d ", data);
			}

		printf("\n");
	} // if

	//22데이터를 찾아 삭제 수행
	
	if(LFirst(&list, &data)){
		if(data==22){
			Rdata=LRemove(&list);
		}
		while(LNext(&list,&data)){
			if(data==22){
			Rdata=LRemove(&list);
			}
		} //while			
	} //if
	
	if(LFirst(&list, &data)){
		printf("%d ", data);

		while(LNext(&list, &data)){
				printf("%d ", data);
			}
	}
		printf("\n");
	
	return 0;
}
