#include<stdio.h>
#include<string.h>
#include<stdlib.h>


//strlen
//sizeof

int main(){

	char ch1[]="hello world";
	
	int len1=strlen(ch1);
	int size1=sizeof(ch1);
	printf("ch1 : %s\n", ch1);
	printf("len1 : %d\n", len1);
	printf("size1 : %d\n", size1);
	
	//strlen은 널문자를 제외한 문자 갯수만 리턴
	//즉, 문자열의 복사 등을 위해서는
	//널 문자를 계산하여야 함.

	

	
	return 0;
}
