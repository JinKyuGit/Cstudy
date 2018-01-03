#include<stdio.h>
#include"deque1.h"


int main(){

	Deque deque;

	DequeInit(&deque);

	AddHead(&deque, 4);
	AddHead(&deque, 3);
	AddHead(&deque, 2);
	AddHead(&deque, 1);

	AddTail(&deque, 5);
	AddTail(&deque, 6);
	AddTail(&deque, 7);
	AddTail(&deque, 8);

	//예상 순서 1, 2, 3 ~ 8


	//주석을 바꿔가며 실행
	while(IsEmpty(&deque)){
	//	printf("꺼낸 데이터 : %d\n", RemoveHead(&deque));
		printf("꺼낸 데이터 : %d\n", RemoveTail(&deque));
	}
	

	return 0;
}
