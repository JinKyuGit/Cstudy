#include<stdio.h>


//두 수를 입력받아 최대공약수와 최소공배수 구하기

//최대 공약수 : 큰 수를 작은 수로 나눴을 때
//나머지가 0인 경우 작은 수가 최대 공약수
//그렇지 않으면 작은수 를 큰수로
//나머지를 작은수로 하여 나머지가 0이 될때까지 반복

//최소 공배수 : 두 수를 곱한 값을 최대공약수로 나눈 값.



int main(){

	int num1=0, num2=0;
	int big, small;
	int temp1; //큰 수를 작은 값으로 나눈 값
	int temp2; //큰 수를 작은 값으로 나눈 나머지.
	int result1, result2;

	printf("첫번째 숫자 입력 : ");
	scanf("%d", &num1);
	printf("두번째 숫자 입력 : ");
	scanf("%d", &num2);
	//예외처리 생략

	if(num1>num2){
		big=num1;
		small=num2;
	}else {
		big=num2;
		small=num1;
	}

	//최대 공약수 판별.
		while(1){
		
			temp1=big/small;
			temp2=big % small;

			if(temp2 == 0){
				result1=small;
				break;
			}else {
				big=small;
				small=temp2;
			} //else
		} // while
	
	result2=(num1*num2)/result1;

	printf("최대 공약수 : %d\n", result1);
	printf("최소 공배수 : %d\n", result2);

	return 0;
}
