#ifndef __TABLE4_H__
#define __TABLE4_H__

//사원관리 테이블 구현.
//테이블은 슬롯 보유.
//키 : 사번
//슬롯idx= 해쉬(키)


#define MAX 100

typedef struct _emp {

	int empNo; //연도 + 네자릿수 인덱스
	char * name; //이름
	char * dept; //부서명

} Emp;

typedef int Key;
typedef Emp* Value;

//해쉬함수.
typedef int Hash(int);
//슬롯 상태. 
enum SlotStatus{EMPTY, DELETED, INUSE};

//슬롯. 슬롯에는 키값과 emp 포인터 저장.
typedef struct _slot {

	Key key; // == empNo
	Value value;
	enum SlotStatus status;

} Slot;

//테이블 - 슬롯배열 및 해시함수
typedef struct _table {
	
	Slot slot[MAX];
	Hash * hash;

} Table;


/////////        Function List       //////////////

//사원 관련
int GetEmpNo(Value value);
Value enrollEmp(int empNo, char * name, char * dept);
void EmpInfo(Value value);

//테이블 관련
void TableInit(Table * table, int len, Hash hash);
int InsertData(Table * table, Value value);
Value SearchData(Table * table, Key key);
int DeleteData(Table * table, Key key);


#endif
