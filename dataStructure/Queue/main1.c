#include<stdio.h>
#include"queue1.h"


int main(){

	//값 넣기
	//뺄값 확인
	//다 빼버리기 - 출력
	

	Queue queue;
	Data data;

	QueueInit(&queue);

	EnQueue(&queue, 1);
	EnQueue(&queue, 2);
	EnQueue(&queue, 3);
	EnQueue(&queue, 4);
	EnQueue(&queue, 5);
	EnQueue(&queue, 6);
	EnQueue(&queue, 7);
	EnQueue(&queue, 8);
	EnQueue(&queue, 9);
	EnQueue(&queue, 10);
		
	printf("front %d rear : %d\n", queue.front, queue.rear);
		printf("삭제 데이터 : %d\n", DeQueue(&queue));
		printf("삭제 데이터 : %d\n", DeQueue(&queue));
		printf("삭제 데이터 : %d\n", DeQueue(&queue));
	printf("================\n");
	EnQueue(&queue, 11);
	EnQueue(&queue, 12);
	//예상 삭제 순서 4, 5, 6 ~ 12
	
	while(IsEmpty(&queue)){
		printf("삭제 데이터 : %d\n", DeQueue(&queue));
	
	}
	
	printf("front %d rear : %d\n", queue.front, queue.rear);


	return 0;
}
