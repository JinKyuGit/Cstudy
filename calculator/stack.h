#ifndef __STACK_H__
#define __STACK_H__

#define LEN 100

typedef int Data;

typedef struct _stack {

	Data arr[LEN];
	int topIndex;

} Stack;


void StackInit(Stack * stack);

int IsEmpty(Stack * stack);

void SPush(Stack * stack, Data data);

Data SPop(Stack * stack);

Data SPeek(Stack * stack);

#endif
