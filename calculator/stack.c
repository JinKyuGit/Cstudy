#include"stack.h"



//초기화
void StackInit(Stack * stack){
	
	stack->topIndex = -1;
}

//비었는지 확인
int IsEmpty(Stack * stack){
	
	if(stack->topIndex == -1){
		return 0;
	}else {
		return 1;
	}
}

//데이터 넣기
void SPush(Stack * stack, Data data){
	
	if(stack->topIndex == LEN -1){
		return;
	}
	
	(stack->topIndex)++;
	stack->arr[stack->topIndex]=data;

}

//빼기 IsEmpty()선행
Data SPop(Stack * stack){

	Data pop=stack->arr[stack->topIndex];
	stack->arr[stack->topIndex]='\0';

	(stack->topIndex)--;

	return pop;
}

Data SPeek(Stack * stack){
	return stack->arr[stack->topIndex];
}

