#include "stack.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//초기화
void StackInit(Stack * stack){

	stack->topIndex = -1;
}

//스택이 비었는지 확인
int IsEmpty(Stack * stack){

	if(stack->topIndex == -1){
		return 0;
	}else {
		return 1;
	}
}
//값 넣기
void SPush(Stack * stack, Data data){

	if(stack->topIndex == LEN -1){
		printf("stack error(not enough memory)\n");
		return;
	}

	(stack->topIndex)++;
	stack->arr[stack->topIndex]=data;
}
//값 빼기
Data SPop(Stack * stack){
	
	Data Rdata=stack->arr[stack->topIndex];
	(stack->topIndex)--;

	return Rdata;
}
//뺄 값 확인
Data SPeek(Stack * stack){
	return stack->arr[stack->topIndex];
}

//기호를 숫자로 리턴.
int OpToNum(char op){

	switch(op){
		case '(':
			return 0;
		case '+':
		case '-':
			return 3;
		case '*':
		case '/':
			return 5;
	} //switch
}

//기호간 우선순위 비교
// +2 기존 기호의 우선순위가 높다 -> 스택 제거
// -2 기존 기호의 우선순위가 낮다 -> 스택 저장
//  0 같다 -> 스택 제거
int GetPriority(char op1, char op2){


	int a=OpToNum(op1);
	int b=OpToNum(op2);
	
	return a - b;
}

//중위식 > 후위식으로 변환
char * Converter(char * infix){
	
	Stack * stack=(Stack *)malloc(sizeof(Stack));
	StackInit(stack);

	int len=strlen(infix);
	//printf("len : %d\n", len);
	//공백 고려해서 사이즈 2배로.
	char * postfix=(char *)malloc(sizeof(len*2));
	int i, j;
	int idx=0;
	char temp;

//	printf("infix : %s\n", infix);
	for(i=0; i<len; i++){
		//숫자인 경우
		//숫자가 끝날 때까지 postifx에 기록하고 공백 추가.
		if(infix[i] >= '0' && infix[i] <= '9'){
			//printf("if 숫자 : %c\n", infix[i]);
				while(1){
					//printf("while문 진입 i: %d\n", i);
					if(infix[i] < '0' || infix[i] > '9'){
						i--;
						//아래 조건문에서 i를 ++하기때문에
						//다시 i를 -- 해야만
						//아래 else 문 작동 가능.
						break;
					}		
					postfix[idx++]=infix[i++];
				}
			postfix[idx++]=' ';
		//기호인 경우
		//1. ( 인 경우. 우선 스택에 저장
		//2. + - * / 인 경우. 기존 스택의 기호와 비교 후 처리
		//3. ) 인 경우. 스택에 있는 기호 전부 제거.
	 	} else { //else 1
		//	printf("else 1 기호 : %c\n", infix[i]);
			if(infix[i] == ')'){
				// ) 가 있는 경우
				// 앞에 ( 가 무조건 있다고 가정.
				while(SPeek(stack) != '('){
					postfix[idx++]=SPop(stack);
				}
				// 스택에서 ( 제거.
				SPop(stack);
				postfix[idx++]=' ';
			}else  if(infix[i] == '('){
				SPush(stack, infix[i]);
				//괄호가 있는 경우는 앞에서 전부 처리하므로
				//괄호가 없다고 가정하고 작성.
				//기호가 나오는 경우. 기존 스택의 기호와
				//우선순위 비교 후 처리.
		} else { //else 2
				if(IsEmpty(stack) == 0){
					SPush(stack, infix[i]);
				}else {
					temp=SPeek(stack);
					//기존 스택에 있던 연산자의 우선순위가 
					//더 높은 경우 > 스택 비움.(연산자 뺌)
					if(GetPriority(temp, infix[i]) == 2 ||
							GetPriority(temp, infix[i]) == 0){
						while(IsEmpty(stack)){
							postfix[idx++]=SPop(stack);
						}
						postfix[idx++]=' ';
						//중요. 새 연산자를 저장해야함.
						SPush(stack, infix[i]);
						//기존 스택 연산자의 우선순위가 낮은경우
						//스택에 계속 저장.
					}else {
						SPush(stack, infix[i]);
					}
					}			
			} //else 2
		} // else 1
	} //for
	
//	printf("IsEmpty :%d\n", IsEmpty(stack));
	//남은 기호 빼기
	while(IsEmpty(stack)){
	//	printf("%d\n", SPeek(stack));
		postfix[idx++]=SPop(stack);
		postfix[idx++]=' ';
	}
	free(stack);
	return postfix;
}


//계산
//숫자를 스택에 저장 후.
//기호가 나타나면 스택에서 값 꺼내어 계산
//이후 계산된 결과를 다시 스택에 저장. 반복.
int Calculate(char * postfix){

	//넘어오는 값 예 : 10 20 30 * +

	Stack * stack=(Stack *)malloc(sizeof(Stack));
	StackInit(stack);

	int len=strlen(postfix);
	int i;
	int idx=0;
	char num[10]; //숫자는 최대 10자리 수라고 가정.
	for(i=0; i<len; i++){
		//이 부분은 변환함수와 유사.
		if(postfix[i] >= '0' && postfix[i] <= '9'){
			while(1){
				if(postfix[i] < '0' || postfix[i] > '9'){
					i--;
					break;
				}
				num[idx++]=postfix[i++];
			}
			SPush(stack, atoi(num));
			idx=0;
			memset(num, '\0', sizeof(10));
		} else { //else 1
			//공백인 경우 continue
			if(postfix[i] == ' '){
				continue;
			}
			//먼저 나오는 값 : 중간결과값이나 두번째 피연산자
			int num2=SPop(stack);
			int num1=SPop(stack);
			//스택의 성격을 고려하여
			//값을 빼고 계산하여 다시 저장
			//ex) 1 2 3 * +
			//스택 : 1 2 3,  postfix * +
			//스택 : 1, 연산 2*3, postfix +
			//스택 1, 6 postfix +
			//스택 1+6  >> 최종결과값.
			//반복.
			switch(postfix[i]){
				case '+':
					SPush(stack, num1+num2);
					break;
				case '-':
					SPush(stack, num1-num2);
					break;
				case '*':
					SPush(stack, num1*num2);
					break;
				case '/':
					SPush(stack, num1/num2);
					break;
			}	//switch
		} //else 1
	} //for
	
	int result=SPop(stack);
	free(stack);
	return result;
}


