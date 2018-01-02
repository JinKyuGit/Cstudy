#include<stdio.h>
#include"queue2.h"


int main(){

	//값 5개 넣고(1,2,3,4,5)
	//2개 삭제 후 (1,2)
	//3개 추가로 넣고(6,7,8)
	//전부 삭제하면서 출력 (순서확인 - 3,4,5 ~ 8)


	Queue queue;
	
	QueueInit(&queue);

	int i;
	for(i=1; i<=5; i++){
		EnQueue(&queue, i);
	}
	
	printf("peek : %d\n", Peek(&queue));
	
	for(i=1; i<=2; i++){
		if(IsEmpty(&queue)){
			printf("삭제 값 : %d\n", DeQueue(&queue));
		}
	}

	for(i=6; i<=8; i++){
		EnQueue(&queue, i);
	}
	printf("peek : %d\n", Peek(&queue));
	while(IsEmpty(&queue)){
			printf("삭제 값 : %d\n", DeQueue(&queue));
	}


	return 0;
}
