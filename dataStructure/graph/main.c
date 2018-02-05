#include<stdio.h>
#include"linkedlist.h"
#include"graph.h"



int main(){


	Graph graph;

	GraphInit(&graph, 5);

	AddEdge(&graph, A, B);
	AddEdge(&graph, A, E);
	AddEdge(&graph, C, D);
	AddEdge(&graph, C, E);

	

	ShowEdgeInfo(&graph);

	GraphFree(&graph);

	return 0;
}
