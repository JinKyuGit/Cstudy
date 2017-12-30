//array stack


typedef int Data;

typedef struct _arrayStack {

	Data arr[100];
	Data topIndex; //가장 마지막에 넣은 값의 index

} Stack;


void StackInit(Stack * stack);

Data IsEmpty(Stack * stack);

void Push(Stack * stack, Data data);
Data Pop(Stack * stack);
Data Peek(Stack * stack);

Data SCount(Stack * stack);
