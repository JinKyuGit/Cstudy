#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__


typedef Slot* Data;

//각각의 노드 - 슬롯의 주소값 저장.
typedef struct _node {

	Data data;
	struct _node * next;

} Node;

int Comp (Node * node1, Node * node2);

typedef struct _list {

	Node * head;
	Node * cur;
	Node * before;
	int numOfData;
	Comp * comp;

} List;

void ListInit(List * list);
void LInsert(List * list, Slot * slot);
Data LFirst(List * list);
Data LNext(List * list);
Data LRemove(List * list);


#endif

