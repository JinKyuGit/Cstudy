#include<stdio.h>


void Swap(int arr[], int idx1, int idx2);

int Partition(int arr[], int left, int right);

void QuickSort(int arr[], int left, int right);

int FindMid(int arr[], int left, int right);

///////////
////////////
//m a i n //
///////////
///////////
int main(){
	

	int arr[5]={3, 4, 1, 5, 2};

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


void Swap(int arr[], int idx1, int idx2){

	int temp=arr[idx1];
	arr[idx1]=arr[idx2];
	arr[idx2]=temp;
}

//적절한 피벗값 탐색
int FindMid(int arr[], int left, int right){

	int a=left;
	int b=(left+right)/2;
	int c=right;

	//요소 3개를 샘플로 수집해서
	//가장 중간값의 인덱스를 리턴.
	
	if(arr[a] > arr[b] && arr[a] < arr[c]){
			return a;
	}else if(arr[b] > arr[a] && arr[b] < arr[c]){
			return b;
	}else {
			return c;
	}
}

//pivot 위치 탐색 및 정렬.
int Partition(int arr[], int left, int right){

	int pivotIdx=FindMid(arr, left, right);
	
	Swap(arr, left, pivotIdx);

	int pivot=arr[left];
	//우선 맨 왼쪽의 값을 피벗으로 정함.

	int low=left+1;
	int high=right;

	while(low <= high){
		
		//조건을 추가하여
		//요소의 값이 같은 경우에도 while문을
		//빠져나올 수 있도록 함.
		//pivot을 제일 왼쪽으로 정했으므로
		//left +1 을 하는 것임.
		while(pivot >= arr[low] && low <= right)
			//피벗보다 작은 값을 만날 때까지.
			low++;
		while(pivot <= arr[high] && high >= left+1)
			//피벗보다 작은 값을 만날 때까지.
			high--;
		
		//두 개의 while문이 끝나고
		//아래의 조건을 만족한다는 것은
		//두 개의 숫자가 각각 pivot을 기준으로
		//작고(low) 크다(high)는 것을 의미.
		if(low <= high){
			Swap(arr, low, high);
		}
	} //while

	//while문의 종료조건은 high = low -1
	//이 자리에 피벗을 위치시킨 후
	//피벗이 위치한 index값을 반환.
	Swap(arr, left, high);
	return high;

}

//pivot을 결정하고 재귀호출.
void QuickSort(int arr[], int left, int right){
	
	if(left<=right){
		//pivot을 구한 뒤
		//pivot을 기준으로 왼쪽 / 오른쪽 요소를 정렬.
		int pivot=Partition(arr, left, right);
		QuickSort(arr, left, pivot-1);
		QuickSort(arr, pivot+1, right);
	}
}
