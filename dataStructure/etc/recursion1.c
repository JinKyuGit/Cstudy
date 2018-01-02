#include<stdio.h>
#include<stdlib.h>


int factorial(int num){

	if(num>1){
	printf("%d x ", num);
	return num*factorial(num-1);

	} else {  //num==1
		printf("%d ", num);
		return 1;
	}
}
	


int main(int argc, char * argv[]){

	if(argc!=2){
		printf("Usage : %s <number>\n", argv[0]);
		return 0;
	}

	int num=atoi(argv[1]);


	int total=factorial(num);

	printf(" = %d\n", total); 
	return 0;
}
