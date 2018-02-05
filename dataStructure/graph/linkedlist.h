#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


typedef int Data;

typedef struct _node {
	
	Data data;
	struct _node * next;

} Node;


typedef struct _list {

	Node * head;
	Node * cur;
	Node * before;
	int numOfData;

} List;

void ListInit(List * list);

void LInsert(List * list, Data data);

Node * LFirst(List * list);
Node * LNext(List * list);

Data LRemove(List * list);


#endif
