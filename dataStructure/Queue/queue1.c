#include <stdio.h>
#include "queue1.h"


//큐 초기화
void QueueInit(Queue * queue){

	queue->front=0;
	queue->rear=0;
	queue->numOfData=0;

}

//큐가 비었는지 확인
int IsEmpty(Queue * queue){

	if(queue->numOfData == 0){
			return 0;
	}else {
			return 1;
	}

}

//큐에 값 넣기 rear이동
void EnQueue(Queue * queue, Data data){

	//용량 확인.
	if(queue->numOfData == LEN){
		printf("큐가 가득 찼습니다.\n");
		return;
	}
	
		queue->arr[(queue->rear)]=data;
		(queue->rear)++;	
		if(queue->rear == LEN){
			//만약 큐가 가득차지 않은 상태에서
			//rear가 배열의 맨 마지막을 가리킨다면
			//rear를 맨 앞으로 이동.
			//front는 삽입시는 불변, 삭제시만 이동.
			queue->rear=0;
		}

	(queue->numOfData)++;
}

//값 빼기. front 이동해야함.
Data DeQueue(Queue * queue){

	Data data=queue->arr[queue->front];	
		(queue->front)++;
	//만일 front ++가
	//배열의 범위를 넘어선다면.
	if(queue->front == LEN){
		queue->front=0;
	}

	(queue->numOfData)--;
	return data;
}

//값 확인 - 삭제 x
Data QPeek(Queue * queue){
	
	Data data=queue->arr[queue->front];
	return data;
}
