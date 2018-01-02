//단순 연결리스트 기반의 Queue 구현


typedef int Data;

typedef struct _node {
	
	Data data;
	struct _node * next;

} Node;

typedef struct _queue {

	Node * front;
	Node * rear;
	int numOfData;

} Queue;

void QueueInit(Queue * queue);

int IsEmpty(Queue * queue);

void EnQueue(Queue * queue, Data data);

Data DeQueue(Queue * queue);

Data Peek(Queue * queue);
