#include<stdio.h>
#include<stdlib.h>
#include "stack1.h"


int main(){

	//초기화
	//값 넣기
	//마지막 값 확인
	//하나씩 빼기
	//전부 다 비워지면 메모리 반환.
	int data;
	Stack * stack=(Stack *)malloc(sizeof(Stack));
	//함수를 통해 생성되는 경우에만 동적메모리 할당 필요
	//그냥 해봤음
	StackInit(stack);
	
	int i=1;
	while(i<=20){
		
		printf("넣을 값 : %d\n", i);
		Push(stack, i);
		i++;
	}

	printf("스택 용량 : %d/100\n", SCount(stack));

	printf("가장 최신값 : %d\n", Peek(stack));

	
	while(IsEmpty(stack)){
		printf("삭제하는 데이터 : %d\n", Pop(stack));
	}
	printf("스택 용량 : %d/100\n", SCount(stack));

	free(stack);

	return 0;
}
