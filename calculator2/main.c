#include<stdio.h>
#include"stack.h"
#include<string.h>


int main(){


	char infix[100];	

	printf("수식 입력 : ");
	fgets(infix, sizeof(infix), stdin);
	
	int len=strlen(infix);
	//개행 제거
	infix[len-1]='\0';
	char * postfix=Converter(infix);
	
	printf("변환된 수식 : %s\n", postfix);
	
	printf("결과 : % d\n", Calculate(postfix));


	return 0;
}
