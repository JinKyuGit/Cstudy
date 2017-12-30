//Doubly Linked List


typedef int Data;

typedef struct _node {

	Data data;
	struct _node * next;
	struct _node * prev;
	
} Node;

typedef struct _list {

	Node * head;
	Node * cur; //양뱡향 연결이므로 bofore 불필요
	int numOfData;

} List;

void ListInit(List * plist);

void LInsert(List * plist, Data data);

Data LFirst(List * plist, Data * pdata);
Data LNext(List * plist, Data * pdata);
Data LPrev(List * plist, Data * pdata);

Data LRemove(List * plist, Data direct);

Data LCount(List * plist);
