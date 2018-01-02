#include<stdio.h>
#include<stdlib.h>

void binarySearch(int arr[], int find, int start, int end){

	//1. 찾는 경우
	//2. 탐색 실패 start>end
	//3. 그 밖의 경우
	
	if(start>end){
		printf("실패\n");
		return;
	}

	int mid=(start+end)/2;
	if(find==arr[mid]){
		printf("성공\n");
		return;
	}else if(find<arr[mid]){
		binarySearch(arr, find, start, end-1);
	}else if(find>arr[mid]){
		binarySearch(arr, find, start+1, end);
		}

}


int main(int argc, char * argv[]){

	if(argc!=2){
		printf("Usage : %s <number>\n", argv[0]);
		return 0;
	}
	int find=atoi(argv[1]);

	int arr[]={1, 3, 6, 13, 16, 20, 27, 33, 35, 40, 45, 50};

	int len=sizeof(arr)/sizeof(int);

	int i;
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
	int start=0;
	int end=len-1;

	binarySearch(arr, find, start, end);
	return 0;
}
