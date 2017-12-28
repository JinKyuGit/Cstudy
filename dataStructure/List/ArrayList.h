

typedef struct {
	
	int arr[100];
	//배열의 크기 100개.
	int numOfData;
	//저장된 데이터의 갯수
	int cursor;
	//현재 가리키는 위치

} List ;

typedef int LData;

void ListInit(List * plist);
void LInsert(List * plist, LData data);
LData LFirst(List * plist, LData * pdata);
LData LNext(List * plist, LData * pdata);
LData LRemove(List * plist);
LData LCount(List * plist);
