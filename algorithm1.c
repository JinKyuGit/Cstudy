#include<stdio.h>


int main(void){

	int maxNum;
	int a=1, b=2;
	int i;
	printf("maxNum : ");
	scanf("%d", &maxNum);

	for(i=1; a<=maxNum; i++){
		printf("%d ", a);
		b+=a;
		a=b-a;
	}
	printf("\n");
	return 0;
}
