#include<stdio.h>
#include<stdlib.h>


void DivideArray(int arr[], int start, int end);
void MergeArray(int arr[], int start, int mid, int end);

//분할 함수
void DivideArray(int arr[], int start, int end){
	

	int mid;
	//분할 조건
	if(start < end){
		mid=(start+end)/2;
			
		DivideArray(arr, start, mid);
		DivideArray(arr, mid+1, end);

		//병합 함수 호출.
		MergeArray(arr, start, mid, end);
		
	}
}

//병합 함수
void MergeArray(int arr[], int start, int mid, int end){

	//arr[]이 논리적으로 두 덩어리로 나뉘어 있다고 가정

	int i; //앞의 덩어리의 시작 index
	int j; //뒤의 덩어리의 시작 index
	int k; // 임시 배열의 시작 index

	int * tempArr=(int *)malloc(sizeof(end+1));

	i=start;
	j=mid+1;
	k=start;
	// 두 덩어리 간의 값을 비교해가며 정렬
	while(i<=mid && j<=end){
		tempArr[k++]=(arr[i] > arr[j]) ? arr[j++] : arr[i++];	
	}
	//while문의 조건이 깨졌을 때
	//정렬이 덜 된 원소가 어느 것인지 파악
	
	int m; //원소가 남은 덩어리 파악
	int n; // for문의 index 끝 찾기.

	m= (i > mid) ? j : i;
	n= (i > mid) ? end : mid;

	for(; m<=n; m++){
		tempArr[k++]=arr[m];
	}


	//이제 원래 배열에 다시 넣음
	for(i=start; i<=end; i++){
		arr[i]=tempArr[i];
	}

	free(tempArr);
	
	//변화 확인.
	printf("start : %d mid : %d end : %d\n", start, mid, end);
	printf("arr : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}


int main(){

	
	int arr[5]={4, 2, 3, 1, 5};
	int i;

	printf("병합 전 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	DivideArray(arr, 0, 4);

	printf("병합 후 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	
	return 0;
}
