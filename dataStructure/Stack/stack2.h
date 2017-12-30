//연결리스트 기반 스택
//새 데이터가 head가 됨.

typedef int Data;

typedef struct _node {

	Data data;
	struct _node * next;

}	Node;

typedef struct _stack {

	Node * head; // head 노드
	Data numOfData; //데이터의 수

}	Stack;


void StackInit(Stack * stack);
int IsEmpty(Stack * stack);
void Push(Stack * stack, Data data);
Data Pop(Stack * stack);
Data Peek(Stack * stack);
