#include <stdio.h>
#include "LinkedList3.h"


int main(){

	//데이터 몇개 입력.
	//출력
	//조건 삭제
	//출력
	
	List list;
	LData data;

	ListInit(&list);
	
	LInsert1(&list, 1);
	LInsert1(&list, 2);
	LInsert1(&list, 3);
	LInsert1(&list, 3);
	LInsert1(&list, 4);
	LInsert1(&list, 5);
	LInsert1(&list, 4);
	LInsert1(&list, 5);
	LInsert1(&list, 2);


	int i;
	if(LFirst(&list, &data)){
			printf("%d ", data);
		for(i=0; i<LCount(&list)*2-1; i++){
				//첫번째 데이터는 이미 조회했으므로 -1
			if(LNext(&list, &data)){
				printf("%d ", data);
			}
			} // for
	} // if
			printf("\n");

	//2의 배수 삭제.
	
	int loop=LCount(&list)-1;
	if(LFirst(&list, &data)){
		if(data%2==0){
			LRemove(&list);
		}

		for(i=0; i<loop; i++){
			if(LNext(&list, &data)){
				if(data%2==0){
				 	LRemove(&list);
				} //if
			}//if
		} // for

	} // if


	loop=LCount(&list)-1;
	if(LFirst(&list, &data)){
			printf("%d ", data);
		for(i=0; i<loop; i++){
			if(LNext(&list, &data)){
				printf("%d ", data);
			}
			} // for
	} // if
 	printf("\n");
	return 0;
}
