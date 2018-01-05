#include<stdio.h>
#include"heap1.h"


int Prior(int a, int b){
	
	//a의 숫자가 더 작다 > 우선순위가 더 높다.
	if(a<b){
		return 1;
	}else {
		return 0;
	}

}


int main(){


	Heap heap;

	HeapInit(&heap, Prior);
	
	HInsert(&heap, 1);
	HInsert(&heap, 3);
	HInsert(&heap, 4);
	HInsert(&heap, 6);
	HInsert(&heap, 7);

	int i;
	for(i=1; i<6; i++){
		printf("%d ", heap.arr[i]);
	}
	printf("\n");
	
	printf("1 데이터 삭제 : %d\n", HDelete(&heap));	
	printf("2 데이터 삭제 : %d\n", HDelete(&heap));
	printf("3 데이터 삭제 : %d\n", HDelete(&heap));
	printf("4 데이터 삭제 : %d\n", HDelete(&heap));
	printf("5 데이터 삭제 : %d\n", HDelete(&heap));
	
	
	
	return 0;
}
