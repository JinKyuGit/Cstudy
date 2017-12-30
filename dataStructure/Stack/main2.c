#include<stdio.h>
#include"stack2.h"



int main(){
	
	//데이터 넣기
	//마지막에 넣은 데이터 확인
	//꺼내기
	
	Stack stack; 
	//  Stack * stack=(Stack *)malloc(sizeof(Stack));
	int size;
	int i;

	StackInit(&stack);

	for(i=1; i<=20; i++){
		printf("삽입 : %d\n", i);
		Push(&stack, i);	
	}

	printf("마지막에 넣은 데이터 : %d\n", Peek(&stack));
	
		
	while(IsEmpty(&stack)){
		printf("삭제 데이터 : %d\n", Pop(&stack));
	}


	return 0;
}
