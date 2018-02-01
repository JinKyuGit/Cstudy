#include<stdio.h>


//보간 탐색

void InterpolSearch(int arr[], int find, int start, int end){

	//이진 탐색과의 차이점1 - 탈출 조건
	if(find < arr[start] || find > arr[end]){
			printf("fail\n");
			return;
	}

	int mid;
	//이진 탐색과의 차이점2 - 보간 구하는 공식.
	mid=((double)(find-arr[start]) / (arr[end]-arr[start])
				* (end-start)) + start;

	if(arr[mid] == find){
			printf("find\n");
			return;
	}else if(arr[mid]>find){
			InterpolSearch(arr, find, start, mid-1);
	}else {
			InterpolSearch(arr, find, mid+1, end);
	}
}


int main(){

	int arr[10]={1, 3, 5, 8, 9, 12, 13, 15, 18, 20};
	int find;
	int i;
	printf("배열 : ");
	for(i=0; i<10; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	printf("찾고자 하는 수 : ");
	scanf("%d", &find);

	InterpolSearch(arr, find, 0, 9);


	return 0;
}
