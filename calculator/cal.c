#include"cal.h"
#include"stack.h"
#include<string.h>
#include<ctype.h>


//계산
int calculator(char exp[]){

	Stack stack;
	StackInit(&stack);

	int len=strlen(exp);
	char op1, op2;
	int i;
	for(i=0; i<len; i++){
		if(isdigit(exp[i])){
		//숫자는 일단 무조건 스택으로
			SPush(&stack, exp[i]-'0');		
		}else{
			//첫번째 pop이 두번째 피연산자가 되어야 한다.
			op2=SPop(&stack);
			op1=SPop(&stack);

			switch(exp[i]){
				case '+':
					SPush(&stack, op1+op2);
					break;
				case '-':
					SPush(&stack, op1-op2);
					break;
				case '*':
					SPush(&stack, op1*op2);
					break;
				case '/':
					SPush(&stack, op1/op2);
					break;
			} //switch
		}//else
	}//for
	return SPop(&stack);
}






