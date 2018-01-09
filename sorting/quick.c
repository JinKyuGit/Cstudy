#include<stdio.h>


int count=1;

void Swap(int arr[], int idx1, int idx2);

void QuickSort(int arr[], int start, int end);

void QuickSort2(int arr[], int start, int end);

void Swap(int arr[], int idx1, int idx2){

	int temp=arr[idx1];
	arr[idx1]=arr[idx2];
	arr[idx2]=temp;
}

void QuickSort(int arr[], int start, int end){
	
	if(start>=end){
		return;
	}

	int mid=(start+end)/2;
	//피봇의 위치는 배열의 중앙값
	int pivot=arr[mid];
	int left=start;
	int right=end;

	while(left <= right){
		//두 개의 while문을 통해
		//left right각각 pivot보다 작거나 큰 값의
		//인덱스를 찾아감.
		while(arr[left] < pivot)
			//pivot보다 크거나 같은 값을 만날 때까지.
			 left++;
		while(arr[right] > pivot)
			//pivot보다 작거나 같은 값을 만날 때까지.
			right--;
		
		if(left <= right){ //if 1
			if(left != right){
				Swap(arr, left, right);
			}
			left++;
			right--;
		}//if 1
	} //while

	printf("정렬 중 arr : ");
	int i;
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	//pivot이 확정된 이후 pivot을 기준으로
	//왼쪽 , 오른쪽 요소들을 정렬함.
	if(start < right){
		QuickSort(arr, start, right);
	}
	if(end > left){
		QuickSort(arr, left, end);
	}
}



int main(){

	int arr[]={3, 5, 1, 2, 4};
	
	int i;

	printf("정렬 전 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	QuickSort(arr, 0, 4);
	
	printf("정렬 후 : ");
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
