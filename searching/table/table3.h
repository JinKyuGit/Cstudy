//슬롯을 활용한 테이블 구현.


#define MAX 100

//사원의 정보를 담을 구조체.
typedef struct _emp {

	int empNo; //연도 + 4자리 인덱스
	char * name;
	int age;

} Emp;


typedef int Key; // key값 - int

typedef Emp* Value; // value값 - emp

//슬롯의 상태표시.
enum SlotStatus {EMPTY, DELETED, INUSE};

//슬롯 구조체.
typedef struct _slot {

	Key key; //int empNo를 hash함.
	Value value; //Emp*
	enum SlotStatus status;

} Slot;

//해쉬함수 등록.
typedef int Hash(int);

//테이블 구조체.
typedef struct _table {

	Slot tbl[MAX];
	Hash * hash;

} Table;


//Emp 관련함수
int GetEmpNo(Emp * emp);
Emp * InsertEmp(int empNo, char * name, int age);
void EmpInfo(Emp * emp);

//슬롯 및 테이블 관련함수.
void TableInit(Table * table, int size, Hash * hash);
Key InsertData(Table * table, Value value);
Value DeleteData(Table * table, int key);
void Search(Table * table, int key);
