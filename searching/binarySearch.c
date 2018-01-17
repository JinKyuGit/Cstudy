#include<stdio.h>



void binarySearch(int arr[], int find, int start, int end){

	if(start>end){
		printf("fail\n");
		return;
	}
	
	int mid=(start+end)/2;
	
	if(arr[mid] == find){
		printf("find\n");
		return;
	}else if(arr[mid] > find){
		binarySearch(arr, find, start, mid-1);
	}else { //arr[mid] < find
		binarySearch(arr, find, mid+1, end);
	}
}


int main(){

	
	int find;
	int arr[5]={2, 3, 5, 7, 9};
	int result;
	int i;

	printf("배열 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n찾고자 하는 수 : ");
	scanf("%d", &find);

	binarySearch(arr, find, 0, 5);


	return 0;
}
