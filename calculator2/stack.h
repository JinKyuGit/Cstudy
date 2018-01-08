#ifndef __STACK_H__
#define __STACK_H__

#define LEN 20

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

int OpToNum(char op);

int GetPriority(char op1, char op2);

char * Converter(char * infix);

int Calculate(char * postfix);

#endif
