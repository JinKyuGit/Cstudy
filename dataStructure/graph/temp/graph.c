#include<stdio.h>
#include<stdlib.h>
#include"graph.h"

//연결리스트 초기화
void ListInit(List * list){

	list->head=NULL;
	list->cur=NULL;
	list->before=NULL;
	list->numOfData=0;
}

//데이터 삽입 - 정렬은 생략.
//데이터의 추가는 헤드에 추가.
void LInsert(List * list, Data data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;
	(list->numOfData)++;

	//첫 삽입인 경우와 아닌경우 고려.
	if(NULL == list->head){
		list->head=newNode;
	}else {
		newNode->next=list->head;
		list->head=newNode;
	} //else 
}
//노드 조회
Node * LFirst(List * list){
	
	if(NULL == list->head){
		return NULL;
	}

	list->cur=list->head;
	list->before=list->head;
	
	return list->cur;
}
//노드 조회 2
Node * LNext(List * list){

	if(NULL == list->cur->next){
			return NULL;
	}

	list->before=list->cur;
	list->cur=list->cur->next;
	
	return list->cur;
}

//노드 삭제
Node * LRemove(List * list){

	Node * del=list->cur;
	
	list->cur=list->before;

	return del;
}

//그래프 초기화
void GraphInit(Graph * graph, int vertex){
	
	graph->vertex=vertex;
	graph->edge=0;
	
	int i;
	for(i=0; i<vertex; i++){
		ListInit( &(graph->list[i]) );
	}

}

//데이터 삽입 - 중복 데이터는 없다고 가정.
void GInsert(Graph * graph, int from, int to){

	LInsert( &(graph->list[from]), to);
	(graph->edge)++;
	
}
//그래프 메모리 해제
void GraphFree(Graph * graph){
	free(graph);
}

//vertex와 edge정보 표시
void ShowInfo(Graph * graph){


	Node * show;
	
	int i;
	for(i=0; i<MAX; i++){
		
		if(NULL != LFirst(&(graph->list[i]) ) ){
			show=LFirst( &(graph->list[i]));
			printf("from %c to %c\n", i+65, show->data+65);
			
			while(NULL != (show = LNext( &(graph->list[i]) ))){
				printf("from %c to %c\n", i+65, show->data+65);	
			} // while
		} // if
	} // for i
}

