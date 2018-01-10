#include<stdio.h>
#include<stdlib.h>
#include"function.h"

//스왑
void Swap(int arr[], int idx1, int idx2){

	int temp=arr[idx1];
	arr[idx1]=arr[idx2];
	arr[idx2]=temp;
}
//출력 - 디버깅
void PrintArr(int arr[], int len){

	printf("출력 : ");
	int i;
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

}
//버블
void BubbleSort(int arr[], int len){
	
	int i, j;

	for(i=0; i<len-1; i++){
		for(j=0; j<len-i-1; j++){
			if(arr[j] > arr[j+1]){
				Swap(arr, j, j+1);
			}
		}
	}
	//	PrintArr(arr, len);
}

//선택
void SelectSort(int arr[], int len){

	int i, j;

	for(i=0; i<len-1; i++){
		for(j=i+1; j<len; j++){
			if(arr[i] > arr[j]){
				Swap(arr, i ,j);
			}
		}
	}
	
	//	PrintArr(arr, len);
}

//삽입
void InsertSort(int arr[], int len){

	int temp;
	int i, j;

	for(i=1; i<len; i++){
		temp=arr[i];
		for(j=i; j>0; j--){	
			if(arr[j-1] > temp){
				arr[j]=arr[j-1];
			}else {
				break;
			}
		}// for
		arr[j]=temp;
	} // for

	//	PrintArr(arr, len);
}

//병합정렬
//배열 쪼개기.
void DivideArr(int arr[], int left, int right){
	
	int mid;
	
	if(left < right){
		
		mid=(left+right)/2;

		DivideArr(arr, left, mid);
		DivideArr(arr, mid+1, right);
		MergeArr(arr, left, mid, right);
	}
}

//병합정렬
//쪼갠 배열 합치기.
void MergeArr(int arr[], int left, int mid, int right){
	
	int * tempArr=(int *)malloc((right+1)*sizeof(int));
	int i, j, k, m, n;

	i=left;
	j=mid+1;
	k=left;

	while(i <= mid && j <= right){
		tempArr[k++] = (arr[i] > arr[j])? arr[j++] : arr[i++];
	}

	m = (i > mid)? j : i;
	n =( i > mid)? right : mid;

	for(; m<=n; m++){
		tempArr[k++] = arr[m];
	}

	for(i=left; i<=right; i++){
		arr[i]=tempArr[i];
	}

	free(tempArr);
}

//퀵 정렬
//pivot 탐색 & 정렬
int Partition(int arr[], int left, int right){

	int pivot=arr[left];
	int low=left+1;
	int high=right;

	while(low <= high){

		while(arr[low] <= pivot && low <= right)
			low++;
		while(arr[high] >= pivot && high >= left+1)
			high--;

		if(low < high){
			Swap(arr, low,high);
		}
	}

	Swap(arr, left, high);
	return high;

}

//재귀
void QuickSort(int arr[], int left, int right){

	if(left > right){
			return;
	}
	
	int pivot=Partition(arr, left, right);
	QuickSort(arr, left, pivot-1);
	QuickSort(arr, pivot+1, right);

}

//힙 초기화
void HeapInit(Heap * heap, Comp comp){

	heap->numOfData=0;
	heap->comp=comp;

}

int IsEmpty(Heap * heap){
	
	if(heap->numOfData == 0){
		return 0;
	}else {
		return 1;
	}
}

int GetParentIdx(int childIdx){
		return childIdx/2;
}

int GetLChildIdx(int parentIdx){
		return parentIdx*2;
}

int GetRChildIdx(int parentIdx){
		return parentIdx*2+1;
}

void HInsert(Heap * heap, int data){
	
	(heap->numOfData)++;
	int idx=heap->numOfData;
	if(idx != 1){
		while(1){
			if(heap->comp(data,
						heap->arr[GetParentIdx(idx)]) == 0){
				break;
			}
			heap->arr[idx]=heap->arr[GetParentIdx(idx)];
			idx=GetParentIdx(idx);
		} //while	
	} //if
	
	heap->arr[idx]=data;
}

//자식 노드 중 우선순위가 높은 데이터 반환.
int GetPriority(Heap * heap, int parentIdx){
	if(heap->numOfData < GetLChildIdx(parentIdx)){
			return 0;
	}else if(heap->numOfData < GetRChildIdx(parentIdx)){
			return GetLChildIdx(parentIdx);
	}else {
		
		if(heap->comp(heap->arr[GetLChildIdx(parentIdx)],
						heap->arr[GetRChildIdx(parentIdx)]) == 1){
			return GetLChildIdx(parentIdx);
		}else {
			return GetRChildIdx(parentIdx);
		}
	}
}
//데이터 삭제. -> 이 과정에서 정렬이 이루어짐.
int HDelete(Heap * heap){
	int Rdata=heap->arr[1];
	int Last=heap->arr[heap->numOfData];
		
	int parentIdx=1;
	int childIdx;
	while(1){
		childIdx=GetPriority(heap, parentIdx);
		//이 경우 자식 노드가 없음을 의미.
		//즉 비교할 것이 없다.
		if(childIdx == 0){
			break;
		}
		//last값이 자식 노드보다 우선순위가 높은 경우.
		if(heap->comp(Last, heap->arr[childIdx]) == 1){
			break;
		}
		//위에 해당하지 않는다면.
		//자식 노드를 위로 한칸씩 올림.
		heap->arr[parentIdx]=heap->arr[childIdx];
		parentIdx=childIdx;
	}
	heap->arr[parentIdx]=Last;
	(heap->numOfData)--;
	return Rdata;
}
