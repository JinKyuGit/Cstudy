#include<stdio.h>

//힙정렬
//힙에 넣고 나오는 과정에서
//정렬이 이루어짐. (우선순위 큐)

#define LEN 5

typedef int (*Comp) (int, int);

typedef struct _heap {
	
	int arr[LEN+1];
	int topIndex;
	Comp comp;

} Heap;

int Compare(int a, int b);

void HeapInit(Heap * heap, Comp comp);

int IsEmpty(Heap * heap);

int GetParentIdx(int childIdx);
int GetLChildIdx(int parentIdx);
int GetRChildIdx(int parentIdx);

void HInsert(Heap * heap, int num);

int GetPriority(Heap * heap, int parentIdx);

int HDelete(Heap * heap);

/////////////
/////////////
////////////
//////////////
//  main

int main(){

	int arr[LEN]={3, 4, 5, 6, 1};
	int i;

	printf("정렬 전 : ");
	for(i=0; i<LEN; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	Heap heap;
	HeapInit(&heap, Compare);

	for(i=0; i<LEN; i++){
		HInsert(&heap, arr[i]);
	}

	printf("heap에 넣은 상태 : ");
	for(i=1; i<LEN+1; i++){
		printf("%d ", heap.arr[i]);
	}	
	printf("\n");


	printf("정렬 후 : ");
	while(IsEmpty(&heap)){
		printf("%d ", HDelete(&heap));
	}

	printf("\n");
	return 0;
}

/////////////
/////////////
////////////
//////////////
//  main

//비교함수
int Compare(int a, int b){
	
	if(a<b){
		return 1;
	}else {
		return 0;
	}
}

//힙 초기화
void HeapInit(Heap * heap, Comp comp){
	heap->topIndex=0;
	heap->comp=comp;
}

//값이 비었는지 확인
int IsEmpty(Heap * heap){
	if(heap->topIndex == 0 ){
		return 0;
	}else {
		return 1;
	}
}

//인덱스값 알아내기
int GetParentIdx(int childIdx){
	return childIdx/2;
}
int GetLChildIdx(int parentIdx){
	return parentIdx*2;
}
int GetRChildIdx(int parentIdx){
	return parentIdx*2+1;
}
//데이터 추가.
//우선 제일 마지막 노드에 넣은 후
//부모 노드와 비교해서 제 자리를 찾아감.
void HInsert(Heap * heap, int num){
		//편의상 가득 찬 경우는 배제.
		
	(heap->topIndex)++;
	int idx=heap->topIndex;

	if(heap->topIndex != 1){
		while(1){
			//부모 노드보다 우선순위가 낮은 경우.
			if(heap->comp(num,
						heap->arr[GetParentIdx(idx)])
					== 0 ){
				break;
			}
			//부모 노드보다 우선순위가 높은 경우.
			heap->arr[idx]=heap->arr[GetParentIdx(idx)];
			idx=GetParentIdx(idx);
		} //while
	} //if

	heap->arr[idx]=num;
}

//특정 부모노드의 자식 중 우선순위가 높은 자식노드의
//index 리턴
int GetPriority(Heap * heap, int parentIdx){

	if(heap->topIndex < GetLChildIdx(parentIdx)){
	//논리상. 자식 노드의 값이 topIndex보다 크다는 것은
	//자식 노드가 없음을 의미.
		return 0;
	}else if(heap->topIndex < GetRChildIdx(parentIdx)){
		return GetLChildIdx(parentIdx);
	}else {
		//두 자식노드가 모두 있는 경우.
		//두 자식 노드의 우선순위 비교.
		if(heap->comp(heap->arr[GetLChildIdx(parentIdx)],
					heap->arr[GetRChildIdx(parentIdx)]) == 1){
			return GetLChildIdx(parentIdx);
		}else {
			return GetRChildIdx(parentIdx);
		}
	}

}

//데이터 삭제. -> 루트 노드 삭제 후
//제일 마지막노드를 루트 노드로 위치시켜
//제자리를 찾아감.
int HDelete(Heap * heap){

	int root=heap->arr[1];
	int last=heap->arr[heap->topIndex];
	
	heap->arr[1]=last;
	int parentIdx=1;
	int childIdx;

	while(1){
		childIdx=GetPriority(heap, parentIdx);
		if(childIdx == 0){
			//이 경우 비교할 값이 없음을 의미.
			break;
		}
		if(heap->comp(heap->arr[parentIdx],
					heap->arr[childIdx]) == 1){
			//이 경우 정렬 끝.
			break;
		}
			//제자리를 찾아갈 때까지 노드 이동.
		heap->arr[parentIdx]=heap->arr[childIdx];
		parentIdx=childIdx;
	}
	//이 때 parentIdx = last데이터가 들어갈 곳.
	heap->arr[parentIdx]=last;
	(heap->topIndex)--;

	return root;
}


