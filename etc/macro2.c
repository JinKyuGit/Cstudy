#include<stdio.h>


#define PLUS(A,B,C) ((A)+(B)+(C))
#define MUL(A,B,C) ((A)*(B)*(C))
#define PI 3.14
#define AREA(A) (A)*(A)*(PI)
#define MAX(A,B) ( (A)>(B) ? (A) : (B) )
int main(){



	printf("PLUS :  %d\n", PLUS(1, 2, 3));
	printf("MUL : %d\n", MUL(1, 2, 3));
	printf("반지름이 3인 원의 넓이 : %f\n", AREA(3));
	printf("2, 3 더 큰 수는? %d\n", MAX(2,3)); 
	return 0;
}
