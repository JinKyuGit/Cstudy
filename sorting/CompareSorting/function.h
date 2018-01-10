//정렬 성능 비교 헤더파일


#define LEN 100001

typedef int (*Comp) (int, int);

typedef struct _heap {

	int arr[LEN];
	int numOfData;
	Comp comp;

} Heap;

//스왑
void Swap(int arr[], int idx1, int idx2);

//출력
void PrintArr(int arr[], int len);

//버블
void BubbleSort(int arr[], int len);

//선택
void SelectSort(int arr[], int len);

//삽입
void InsertSort(int arr[], int len);

//병합정렬
void DivideArr(int arr[], int left, int right);
void MergeArr(int arr[], int left, int mid, int right);

//퀵 정렬
int Partition(int arr[], int left, int right);
void QuickSort(int arr[], int left, int right);

//힙 정렬
void HeapInit(Heap * heap, Comp comp);
int IsEmpty(Heap * heap);
int GetParentIdx(int childIdx);
int GetLChildIdx(int parentIdx);
int GetRChildIDx(int parentIdx);
void HInsert(Heap * heap, int data);
int GetPriority(Heap * heap, int parentIdx);
int HDelete(Heap * heap);

