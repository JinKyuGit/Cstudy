#include<stdio.h>

#define NAME "jinkyu"

//#define SQUARE(X) X*X - wrong
#define SQUARE(X) ((X)*(X))

#define DIFF_ABS(X, Y) ( (X)>(Y) ? (X)-(Y) : (Y)-(X) )

#define ADD 1

#define STRING(A,B) #A" plus "#B" = "

#define PLUS(A,B) ((A)+(B))

#define PLUS2(A, B, C) A##B##C
int main(){
	
	int num1=2;
	int num2=3;

	printf("define NAME : %s\n", NAME);

	printf("define SQUARE : %d\n", SQUARE(num1+num2));
	
	printf("define DIFF_ABS :  %d\n", DIFF_ABS(num1, num2));

	printf("define STRING and PLUS : %s%d\n", STRING(2, 3), PLUS(num1,num2));
	int num3=PLUS2(2, 3, 4);
	printf("define PLUS2 : %d\n", num3);

#ifdef ADD
	printf("ADD is defined\n");
#endif

#if ADD
	printf("ADD is true\n");
#else
	printf("ADD is false\n");
#endif

		return 0;  
}
