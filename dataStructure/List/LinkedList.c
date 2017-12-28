#include<stdio.h>
#include<stdlib.h>


typedef struct node {

	int data;
	struct node * next;

} Node;


int main(){

	Node * newNode;
	Node * head;
	Node * tail;
	Node * cur;
	//삽입
	while(1){
		printf("입력(종료는 0) : ");
		int temp;
		scanf("%d", &temp);
		if(temp==0){
			break;
		}

		newNode=(Node *)malloc(sizeof(Node));
		newNode->data=temp;
		newNode->next=NULL;
		//첫번째 노드면 head, 그다음부터는 계속 tail 갱신
		if(head==NULL){
			head=newNode;
		}else {
			//특정 노드는 다음 노드의 주소를 저장하고 있어야 함.
			tail->next=newNode;
		}
		tail=newNode;
	} //while

	//조회
	printf("전체출력\n");

	if(NULL==head){
		printf("입력된 데이터가 없습니다.\n");
		return 0;
	}
	//첫번째 데이터 출력
	printf("데이터 : %d 다음노드 위치 : %p\n", head->data, head->next);
	cur=head->next;
	//마지막 이전까지 데이터 출력
	while(NULL != (cur->next)){
		printf("데이터 : %d 다음노드 위치 : %p\n", cur->data, cur->next);
		cur=cur->next;
	}
	//마지막 데이터
	printf("데이터 : %d\n", cur->data);

	printf("=== 메모리 해제 ===\n");
	//메모리 해제
	while(NULL != cur){
		printf("삭제 데이터 %d, 다음 노드위치 %p\n",
				head->data, head->next);
		cur=head->next;
		free(head);
		head=cur;
		cur=cur->next;
	}
	printf("삭제 데이터 %d\n", head->data);
 	free(head);		
	


	return 0;
}
