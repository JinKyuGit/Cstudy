#include<stdio.h>
#include"heap1.h"


//힙 초기화
void HeapInit(Heap * heap, Comp comp){
	
	heap->numOfData=0;
	heap->comp=comp;

}

//비었는지 확인 -> 삭제시 선행.
int IsEmpty(Heap * heap){

	if(heap->numOfData == 0){
		return 0;
	}else {
		return 1;
	}
}
//데이터 삽입 등을 위해 필요한 함수들
//1. 부모 인덱스 알아내기
//2. 왼쪽 자식 인덱스
//3. 오른쪽 자식 인덱스
//4. 우선순위가 높은 자식의 인덱스 반환함수

int ParentIdx(int idx){
	return idx/2;
}

int LChildIdx(int idx){
	return idx*2;
}

int RChildIdx(int idx){
	return idx*2+1;
}
//두 개의 자식 노드 중 높은 우선순위의 인덱스 반환
//자식이 없으면 0
//조건 1. 자식 노드가 없는 경우
//조건 2. 자식 노드가 하나인 경우
//조건 3. 자식 노드가 2개인 경우 > 높은 우선순위 idx 반환
int GetPriority(Heap * heap, int idx){
	//매개변수 idx란 부모 노드의 idx를 의미
	if(LChildIdx(idx) > heap->numOfData){
		//자식 노드의 인덱스 값이 numOfData보다 크다는 것은
		//데이터가 없음을 의미
	//	printf("if문에 걸림\n");
		return 0;
	}else if(RChildIdx(idx) > heap->numOfData) {
		//위와 마찬가지로 왼쪽 자식 노드는 있으나
		//오른쪽 자식노드는 없음을 의미
	//	printf("else if문에 걸림\n");
		return LChildIdx(idx);
	}else {
		if(heap->comp(heap->arr[LChildIdx(idx)],
					heap->arr[RChildIdx(idx)]) == 1){
		//	printf("else - 왼쪽\n");
			return LChildIdx(idx);
		}else { // 위의 조건식이 == 0
		//	printf("else - 오른쪽\n");
			return RChildIdx(idx);
		}
	} // else
		
}
//데이터 삽입
//우선 제일 마지막 노드에 삽입한 후
//부모 노드와의 비교를 통해 자리를 결정
//자식 노드간에는 비교할 필요 없음.
void HInsert(Heap * heap, Data data){

	int idx=heap->numOfData+1;

	//첫 데이터인 경우 반복문 필요없음.
	if(idx!=1){
		while(1){
			if(heap->comp(data, heap->arr[ParentIdx(idx)]) == 0){
				//새 데이터(마지막 노드라고 가정)와
				//부모 데이터간의 비교
				// 0값이 넘어오면 새 데이터의 우선순위가 낮다는 것
				break;
			}else {
				//새 데이터의 우선순위가 높은 경우
				//부모 데이터를 자식 노드로 내림.
				heap->arr[idx]=heap->arr[ParentIdx(idx)];
				idx=ParentIdx(idx);
			} //else
		}//while
	}// if

	//반복이 끝난 후 idx -> 새 데이터가 들어갈 위치
	heap->arr[idx]=data;
	(heap->numOfData)++;
}
//데이터의 삭제 - 루트노드
//제일 마지막 노드를 루트 노드로 올린다음
//해당 노드의 자리를 찾아가면서 정렬.
Data HDelete(Heap * heap){
	
	Data Rdata=heap->arr[1];
	Data LastData=heap->arr[heap->numOfData];

	int parentIdx=1;
	int childIdx;

	heap->arr[1]=LastData;

	while(1) {
		childIdx=GetPriority(heap, parentIdx);
		
	//	printf("parentIdx : %d\n",parentIdx);
	//	printf("childIdx : %d\n", childIdx);
	//	printf("=======\n");
		if(childIdx == 0){
			break;
		}
		if(heap->comp(LastData, heap->arr[childIdx]) == 1){
			//옮긴 노드가 그 아래 자식노드보다
			//우선순위가 높은 경우
			//즉 제자리를 찾은 경우.
			break;
		}
	
		heap->arr[parentIdx]=heap->arr[childIdx];
		parentIdx=childIdx;

	} //while

	heap->arr[parentIdx]=LastData;
	(heap->numOfData)--;
	return Rdata;
}
