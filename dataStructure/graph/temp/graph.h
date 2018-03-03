#ifndef __GRAPH_H__
#define __GRAPH_H__

//연결리스트를 통한 간단한 그래프 구현.

#define MAX 7

enum {A, B, C, D, E, F, G};


typedef int Data;

typedef struct _node {

	Data data;
	struct _node * next;

} Node;

typedef struct _list {
	
	Node * head;
	Node * before;
	Node * cur;
	int numOfData;

} List;


typedef struct _graph {

	List list[MAX];
	int vertex;
	int edge;

} Graph;


void ListInit(List * list);
void LInsert(List * list, Data data);
Node * LFirst(List * list);
Node * LNext(List * list);
Node * LRemove(List * list);

void GraphInit(Graph * graph,int vertex);
void GInsert(Graph * graph, int from, int to);
void GraphFree(Graph * graph);
void ShowInfo(Graph * graph);

#endif
