#include "queue2.h"
#include <stdlib.h>


//초기화
void QueueInit(Queue * queue){

	queue->front=NULL;
	queue->rear=NULL;
	queue->numOfData=0;
}

//비었는지 확인
int IsEmpty(Queue * queue){

	if(queue->numOfData == 0){
		//NULL == queue->front(or rear)로 해도 무방.
		return 0;
	}

		return 1;

}

//데이터 추가
void EnQueue(Queue * queue, Data data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	
	//첫 삽입인 경우 front == rear
	if(NULL == queue->front){
		queue->front=newNode;
		queue->rear=newNode;
	} else {
		//새로운 노드가 rear가 됨. 즉, rear이동.
		queue->rear->next=newNode;
		queue->rear=newNode;
	}

	(queue->numOfData)++;

}

//값 꺼내기 -> 삭제. IsEmpty()로 조건검사 필요.
Data DeQueue(Queue * queue){
	
	Node * delNode=queue->front;
	Data data=delNode->data;
	//front 이동.
	queue->front=queue->front->next;
	
	free(delNode);
	(queue->numOfData)--;

	return data;
}

//값 확인 IsEmpty()로 조건검사 필요.
Data Peek(Queue * queue){
	return queue->rear->data;
}
