#include<stdio.h>
#include<stdlib.h>


int main(void){

	int * ptr;
	ptr=(int *)malloc(sizeof(int)*5);
	//우선 5개 할당
	
	int temp;
	int count=0;
	int size=5;
	while(1){
		printf("%d번째 정수입력 : ", count+1);
		scanf("%d", &temp);
		//탈출조건
		if(temp==-1)
			break;
		//메모리 재할당
		if(count>size){
			ptr=(int *)realloc(ptr, sizeof(int)*(count+3));
			size=count+3;
		}
		ptr[count]=temp;
		count++;
	}
	//출력
	int i;
	for(i=0; i<count; i++){
		printf("%d ", ptr[i]);
	}


	free(ptr);
	printf("\n");
	return 0;
}
