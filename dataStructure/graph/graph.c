#include<stdio.h>
#include<stdlib.h>
#include"linkedlist.h"
#include"graph.h"

//그래프 초기화
void GraphInit(Graph * graph, int vertex){

	graph->arr=(List *)malloc(sizeof(List)*vertex);
	graph->vertex=vertex;
	graph->edge=0;

	//리스트 초기화
	int i;
	for(i=0; i<vertex; i++){
		ListInit( &(graph->arr[i]) );
	}
}

//그래프 메모리 반환
void GraphFree(Graph * graph){

		free(graph->arr);
}

//간선(Edge) 연결
void AddEdge(Graph * graph, int from, int to){

	//무방향 그래프이므로 양방향 연결.
	LInsert( &(graph->arr[from] ) , to);
	LInsert( &(graph->arr[to] ) , from);
	(graph->edge)++;
}

//간선 정보 출력.
void ShowEdgeInfo(Graph * graph){

	int i;
	int len;
	for(i=0; i<graph->vertex; i++){
			
		if(NULL != LFirst( &(graph->arr[i]) )){
			
			Node * temp=LFirst( &(graph->arr[i]));
			printf("from %c to %c\n", i+65, (temp->data)+65);
			
			while(NULL != (temp=LNext( &(graph->arr[i]) ))){
				printf("from %c to %c\n", i+65, (temp->data)+65);
			} // while
		} //if	
	} //for i
}



