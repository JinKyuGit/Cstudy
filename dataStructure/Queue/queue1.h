//배열기반 큐 - circular Queue



typedef int Data;

#define LEN 10

typedef struct _queue {

	int front;
	int rear;
	Data arr[LEN];
	int numOfData;

} Queue;


void QueueInit(Queue * queue);

int IsEmpty(Queue * queue);

void EnQueue(Queue * queue, Data data);

Data DeQueue(Queue * queue);

Data QPeek(Queue * queue);
