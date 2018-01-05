#ifndef __HEAP1_H__
#define __HEAP1_H__


#define LEN 20

typedef int Data;

typedef int Comp(int, int);

typedef struct _heap {

	Data arr[LEN];
	int numOfData;
	Comp * comp; //우선순위 함수

} Heap;

void HeapInit(Heap * heap, Comp comp);

int IsEmpty(Heap * heap);

void HInsert(Heap * heap, Data data);
Data HDelete(Heap * heap);

int ParentIdx(int idx);
int	LChildIdx(int idx);
int RChildIdx(int idx);

int GetPriority(Heap * heap, int idx);

#endif
