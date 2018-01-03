#ifndef __DEQUE1_H__
#define __DEQUE1_H__


typedef int Data;

typedef struct _node {

	Data data;
	struct _node * next;
	struct _node * prev;

} Node;

typedef struct _deque {

	struct _node * head;
	struct _node * tail;
	int numOfData;

} Deque;

void DequeInit(Deque * deque);

int IsEmpty(Deque * deque);

void AddHead(Deque * deque, Data data);
void AddTail(Deque * deque, Data data);

Data RemoveHead(Deque * deque);
Data RemoveTail(Deque * deque);

#endif
