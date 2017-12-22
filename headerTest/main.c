#include <stdio.h>
#include "header1.h"


int main(){

	double num1, num2;

	printf("첫번째 숫자 입력 : ");
	scanf("%lf", &num1);
	printf("두번째 숫자 입력 : ");
	scanf("%lf", &num2);

	printf("두 수의 합 : %f\n", add(num1, num2));
	printf("두 수의 차 : %f\n", minus(num1, num2));
	printf("두 수의 곱 : %f\n", multiple(num1, num2));
	printf("두 수의 나눗셈 : %f\n", divide(num1, num2));



	return 0;
}
