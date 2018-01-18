#include<stdio.h>


int main(){

	int num=10;

	int * ptr=&num;

	int ** dptr=&ptr;

	printf("num : %d\n", num);
	printf("*ptr : %d\n", *ptr);
	printf("**dptr : %d\n", **dptr);

	
	printf("&num : %p\n", &num);
	printf("ptr : %p\n", ptr);
	//ptr에는 num변수의 주소값 저장.	

	printf("&ptr : %p\n", &ptr);
	printf("dptr : %p\n", dptr);
	//dptr에는 ptr 포인터 변수의 주소값 저장. 
	return 0;
}
