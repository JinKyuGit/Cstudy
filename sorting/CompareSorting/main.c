#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include"function.h"


int Compare(int a, int b){
	
	if(a<b){
		return 1;
	}else {
		return 0;
	}
}


//각 정렬 별로 성능 계산기 작성.

int main(int argc, char * argv[]){

	if(argc != 2){
		printf("Usage : %s <size of Array>\n", argv[0]);
		return 0;
	}

	//입력받은 크기만큼 배열 생성.
	int n=atoi(argv[1]);
//	printf("n : %d\n", n);
	int * arr=(int *)malloc(n*sizeof(int));
	int * arr1=(int *)malloc(n*sizeof(int));
	int * arr2=(int *)malloc(n*sizeof(int));
	int * arr3=(int *)malloc(n*sizeof(int));
	int * arr4=(int *)malloc(n*sizeof(int));
	int * arr5=(int *)malloc(n*sizeof(int));
	int * arr6=(int *)malloc(n*sizeof(int));
	int * arr7=(int *)malloc(n*sizeof(int));	
	//배열에 랜덤값 넣기.
	srand((int)time(NULL));
	int i;
	for(i=0; i<n; i++){
		arr[i]=(rand()% 9999)+1;
		arr1[i]=arr[i];
		arr2[i]=arr[i];
		arr3[i]=arr[i];
		arr4[i]=arr[i];
		arr5[i]=arr[i];
		arr6[i]=arr[i];
		
		//기수 정렬의 maxLen을 위한 조치.
		if(i < n-1){
			arr7[i]=arr[i];
		}
	}
	//기수 정렬을 위해 arr7의 맨 마지막 요소는 네자릿수 집어넣음.
	arr7[n-1]=9999;

	//시간 계산 변수.
	time_t start, end;
	double gap;

	start=clock();
	end=clock();
	gap=(double)(end-start)/(double)1000;

	//정렬 성능 비교
	printf("=== 정렬 성능 비교 프로그램 ===\n");
	printf("입력한 배열의 갯수 : %d\n", n);
	printf("\n--- 정렬 시작 ---\n");

	if(n<=100000){
	//버블
	start=clock();
	BubbleSort(arr1, n);
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf("버블 정렬 : %lf초\n", gap);	
	free(arr1);
	
	//선택
	start=clock();	
	SelectSort(arr2, n);
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf("선택 정렬 : %lf초\n", gap);
	free(arr2);
	//삽입
	start=clock();
	InsertSort(arr3, n);	
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf("삽입 정렬 : %lf초\n", gap);
	free(arr3);	
	}else {
		printf("버블, 선택, 삽입정렬은 100000개 이하만 실행.\n");
		printf("너무 오래 걸림... \n");
		free(arr1);
		free(arr2);
		free(arr3);
	}
	
	//병합.
	start=clock();
	DivideArr(arr4, 0, n-1);
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf("병합 정렬 : %lf초\n", gap);
	free(arr4);
	
	//힙
	if(n <= 100000){
		Heap heap;
		HeapInit(&heap, Compare);
		start=clock();
		for(i=0; i<n; i++){
			HInsert(&heap, arr5[i]);
		}
		while(HIsEmpty(&heap)){
			HDelete(&heap);
		}
		end=clock();
		gap=(double)(end-start)/CLOCKS_PER_SEC;
		printf(" 힙  정렬 : %lf초\n", gap);
		free(arr5);
	}else{
		printf("heap 정렬은 100000개 이하일때만 실행.\n");
		free(arr5);
	}
	//퀵
	start=clock();
	QuickSort(arr6, 0, n-1);
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf(" 퀵  정렬 : %lf초\n", gap);
	free(arr6);

	//기수정렬.
	start=clock();
	RadixSort(arr7, n, 4);
	end=clock();
	gap=(double)(end-start)/CLOCKS_PER_SEC;
	printf("기수 정렬 : %lf초\n", gap);
	free(arr7);


	return 0;
}
