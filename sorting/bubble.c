#include<stdio.h>


//버블정렬 알고리즘
//시간복잡도 O(n제곱)


int main(){


	int arr[5]={3, 4, 6, 2, 1};
	int i, j;
	int len=sizeof(arr)/sizeof(int);
	int temp;

	printf("정렬 전 : ");

	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");


	// 배열의 맨 처음부터 순차적으로 시작
	// 배열의 특정 요소가 다음 요소보다 작거나 큰 경우
	// 둘의 순서를 바꿈.
	for(i=0; i<len-1; i++){
		for(j=0; j<len-i-1; j++){
			if(arr[j] > arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}

	printf("정렬 후 : ");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;

}
