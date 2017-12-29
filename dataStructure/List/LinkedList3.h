//circular Linked List


typedef int LData;

typedef struct _node {

	LData data;
	struct _node * next;

} Node;

typedef struct CircularLinkedList {
	
	Node * tail; // 노드의 끝 head는 tail->next
	Node * cur; // 현재위치 노드
	Node * before; // 현재 위치 -1 노드
	LData numOfData; // 노드의 수
} List;

void ListInit(List * plist);

void LInsert1(List * plist, LData data); //tail에 추가
void LInsert2(List * plist, LData data); //head에 추가

LData LFirst(List * plist, LData * data);
LData LNext(List * plist, LData * data);

LData LRemove(List * plist);

LData LCount(List * plist);

