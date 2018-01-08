#include "stack.h"
#include "converter.h"
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

//연산자의 우선순위에 따른 값 반환
//* / 3
//+ - 2
// (  1
int OpToNum(char op){

	int prior;

	switch(op){
		case '*':
		case '/':
			return 3;
		case '+':
		case '-':
			return 2;
		case '(':
			return 0;
		default :
			break;
	}

	return -1;

}
//어떤 연산자의 우선순위가 앞서는지 반환.
int GetPriority(char op1, char op2){

	return OpToNum(op1)-OpToNum(op2);
	
	//값이 1 : 앞의 연산자의 우선순위가 높다
	//값이 -1 : 앞 연산자의 우선순위가 낮음
	//그 밖의 값 : 비교한 연산자가 (인 경우. 무시.

}
//변환 후 exp에 담아서 보냄.
void Convert(char exp[]){
	
	Stack stack;
	int len=strlen(exp);
	StackInit(&stack);
	//printf("len : %d\n", len);
	char * convExp=(char *)malloc(sizeof(len+1));
	memset(convExp, 0, sizeof(len+1));
	char pop;
	int i;
	int idx=0;
	for(i=0; i<len; i++){
		//숫자인 경우 순서대로 담는다.
		//구분 지어야 하는 것
		//1. 숫자
		//2. 사칙연산자
		//3. (
		//4. )  >> 이 경우 스택에 있는 것을 다 제거
		if(isdigit(exp[i])){
			
			convExp[idx++]=exp[i];

		}else if(exp[i] == '('){
		
			SPush(&stack, exp[i]);

		}else if(exp[i] == ')'){
			//이 경우 스택에 있는 연산자를 다 옮겨야 한다.
			while(SPeek(&stack) != '('){
			  convExp[idx++]=SPop(&stack);
			} //while
				// '('제거
				SPop(&stack);
		} else {
		//	printf("else : %c\n", exp[i]);
			//일반 사칙연산자인 경우, 기존 스택의 것과 비교
			//기존 연산자의 우선순위가 높으면 스택을 비우고
			//그게 아니라면 쌓아둠.
			if(GetPriority(SPeek(&stack), exp[i]) == 1){
				//스택에 있는 연산자의 우선순위가 높은 경우
				while(IsEmpty(&stack)){
					convExp[idx++]=SPop(&stack);
				}
				//다 비우고 나서 새로운 기호 저장
				SPush(&stack, exp[i]);
			}else {
				SPush(&stack, exp[i]);
			}
		}//else
	}//for

	//for문이 끝나면. 스택에 남은 연산자를 순서대로 옮긴다.
	while(IsEmpty(&stack)){
		convExp[idx++]=SPop(&stack);
	}
	//문자열을 exp에 복사한다.
	strcpy(exp, convExp);
	free(convExp);

}

