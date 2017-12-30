#include<stdio.h>
#include "stack1.h"



//초기화
void StackInit(Stack * stack){
	
	stack->topIndex=-1;
	//값이 아직 없으므로.
}

//비었는지 확인
Data IsEmpty(Stack * stack){
 	
	if(stack->topIndex == -1){
		return 0;
	}else {
		return 1;
	}
}

//값 넣기
void Push(Stack * stack, Data data){
	
	if(stack->topIndex == 99){
		printf("스택이 가득 찼습니다.\n");
		return;
	}

	(stack->topIndex)++;
	stack->arr[stack->topIndex]=data;
	return;
}

//맨 마지막 데이터 삭제 - 삭제한 값 반환
Data Pop(Stack * stack){
	//IsEmpty를 통해 값의 유무를 따질 것이므로
	//조건 검사를 할 필요가 없음
	
	Data data=stack->arr[stack->topIndex];
	stack->arr[stack->topIndex]=0;
	(stack->topIndex)--;

	return data;

}

Data Peek(Stack * stack){
	Data data=stack->arr[stack->topIndex];
	return data;
}

Data SCount(Stack * stack){

	if(stack->topIndex == -1) {
		printf("데이터가 없습니다.\n");
		return 0;
	}

	return (stack->topIndex)+1;
}


