#ifndef __GRAPH_H__
#define __GRAPH_H__

enum {A, B, C, D, E, F ,G};


typedef struct _graph {

	List * arr;
	int vertex;
	int edge;
	
} Graph;

void GraphInit(Graph * graph, int vertex);

void GraphFree(Graph * graph);

void AddEdge(Graph * graph, int from, int to);

void ShowEdgeInfo(Graph * graph);



#endif
