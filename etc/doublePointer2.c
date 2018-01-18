#include<stdio.h>



//포인터가 가리키는 변수의 값이 서로 바뀜.
void Swap1(int *ptr1, int * ptr2){

	int temp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2=temp;
}

//포인터가 가리키는 변수가 서로 바뀜.(주소값 교환)
//포인터가 가리키는 변수의 값은 변하지 않음.
void Swap2(int **dptr1, int **dptr2){

	int * temp= *dptr1;
	*dptr1=*dptr2;
	*dptr2=temp;
}

int main(){

	int num1=10;
	int num2=20;

	int * ptr1=&num1;
	int * ptr2=&num2;

	printf("num1 : %d, num2 :%d\n", num1, num2);
	printf("ptr1 : %p, ptr2 : %p\n", ptr1, ptr2);
//	Swap1(ptr1, ptr2);
//	printf("after Swap1\n");
//	printf("num1 : %d, num2 :%d\n", num1, num2);
//	printf("ptr1 : %p, ptr2 : %p\n", ptr1, ptr2);
	Swap2(&ptr1, &ptr2);
	printf("after Swap2\n");
	printf("num1 : %d, num2 :%d\n", num1, num2);
	printf("ptr1 : %p, ptr2 : %p\n", ptr1, ptr2);
	return 0;
}
