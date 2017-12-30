#include <stdio.h>
#include "LinkedList4.h"


int main(){

	//초기화
	//데이터 몇개 삽입
	//출력
	// 순방향 이동 / 역방향 이동
	// 데이터 몇개 삭제
	// 출력
	
	List list;
	Data data;
	
	ListInit(&list);
	
	LInsert(&list, 11); // head
	//head에 추가되는 방식이므로 데이터를 거꾸로 삽입해야함.
	//tail에 추가하려면 head->prev에 추가되는 형식으로
	//LInsert 수정.
	LInsert(&list, 88);
	LInsert(&list, 77);
	LInsert(&list, 66);
	LInsert(&list, 55);
	LInsert(&list, 44);
	LInsert(&list, 33);
	LInsert(&list, 22);

	//데이터 수 기록
	int len=LCount(&list);
	printf("데이터의 수 : %d\n", len);
	int i;
	//순방향 출력
	printf("순방향 출력\n");
	if(LFirst(&list, &data)){
		printf("%d ", data);
		for(i=0; i<len-1; i++){
			if(LNext(&list, &data)){
				printf("%d ", data);
			} // if
		} // for
	} // if
	printf("\n");
	//역방향 출력 - head->prev부터
	printf("역방향 출력\n");
	
	if(LFirst(&list, &data)){
		//이 경우 cur위치 = head
		//따라서 출력x
		for(i=0; i<len; i++){
			if(LPrev(&list, &data)){
				printf("%d ", data);		
			}//if
		} // for
	}//if
	printf("\n");
	
	int del;
	// 짝수 데이터를 가진 노드 삭제
	if(LFirst(&list, &data)){
		if(data%2==0){
			del=LRemove(&list, 0);
			printf("삭제된 데이터 : %d\n", del);
		}
		for(i=0; i<len-1; i++){
			if(LNext(&list, &data)){
				if(data%2==0){
					del=LRemove(&list, 0);
					printf("삭제된 데이터 : %d\n", del);
				}
			} //if
		} //for
	} //if

	len=LCount(&list);
	//데이터의 수가 줄었으므로 len 재설정.

	if(LFirst(&list, &data)){
		printf("%d ", data);
		for(i=0; i<len-1; i++){
			if(LNext(&list, &data)){
				printf("%d ", data);
			} // if
		} // for
	} // if
	printf("\n");

	return 0;
}
