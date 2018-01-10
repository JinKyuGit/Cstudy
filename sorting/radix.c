#include<stdio.h>
#include<stdlib.h>

//큐를 이용한 기수정렬 구현.

typedef struct _node {

	int data;
	struct _node * next;

} Node;

typedef struct _queue {

	Node * front;
	Node * rear;

} Queue;

void QueueInit(Queue * queue);
int IsEmpty(Queue * queue);
void EnQueue(Queue * queue, int data);
int DeQueue(Queue * queue);

void RadixSort(int arr[], int len, int maxLen);

int main(){


	int arr[]={3, 5, 1, 2, 6};

	RadixSort(arr, 5, 1);

	int i;
	for(i=0; i<5; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	
	
	return 0;
}

void QueueInit(Queue * queue){
	
	queue->front=NULL;
	queue->rear=NULL;
}

int IsEmpty(Queue * queue){

	if(NULL == queue->front){
		return 0;
	}else {
		return 1;
	}
}

void EnQueue(Queue * queue, int data){

	Node * newNode=(Node *)malloc(sizeof(Node));
	newNode->data=data;
	newNode->next=NULL;

	//첫 삽입인 경우와 아닌 경우.
	if(NULL == queue->front){
		queue->front=newNode;
		queue->rear=newNode;
	}else {
		queue->rear->next=newNode;
		queue->rear=newNode;
	}
}

int DeQueue(Queue * queue){

	Node * delNode=queue->front;
	int Rdata=delNode->data;
	
	queue->front=queue->front->next;
	
	return Rdata;
}

//기수정렬 함수
//가장 아래 자릿수부터
//순서가 정해진 bucket에 넣었다가 뺐다가를 반복.
void RadixSort(int arr[], int len, int maxLen){

	//10진수 0~9 필요한 버킷 수 10개.
	Queue bucket[10];
	int i, j;
	int k=0;//arr 인덱스값.
	int radix; //기수 = num / divide % 10 
	int divide=1; //1,10, 100..
	//큐 초기화.
	for(i=0; i<10; i++){
		QueueInit(&bucket[i]);	
	} 
	//요소 중 최대길이 원소의 길이만큼 반복
	for(i=0; i<maxLen; i++){
			//배열의 크기만큼 반복해서
			//버킷에 순서대로 넣음.
		for(j=0; j<len; j++){
			radix=(arr[j]/divide)% 10;

			EnQueue(&bucket[radix], arr[j]);
		}
			//버킷의 크기만큼
			//순서대로 꺼내는 작업.
		for(j=0; j<10; j++){
			while(IsEmpty(&bucket[j])){
				arr[k++]=DeQueue(&bucket[j]);

			} //while
		} //for
		//자릿수 증가작업.
		k=0;
		divide = divide * 10; 
	} //for
}

