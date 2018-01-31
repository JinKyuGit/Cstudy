#ifndef __TABLE_H__
#define __TABLE_H__

#define MAX 100  //List 배열의 크기.

//사원 정보를 저장할 노드
typedef struct _emp {

	int empNo; //key
	char * name;
	struct _emp * next;
	
}Emp;

typedef int Key;
typedef Emp* Value;

typedef int Comp (int, int);

//연결리스트
typedef struct _list {
	
	Emp * head;
	Emp * cur;
	Emp * before;
	int numOfData;
	Comp * comp; //노드간 우선순위 비교함수.

}List;

typedef int Hash (int);

//테이블.
typedef struct _table {
	
	List list[MAX];
	Hash * hash; //키값을 이용하여 인덱스 결정할 해쉬함수.

} Table;


/*
  Function List
                */

//Emp function
Value Enroll(int empNo, char * name); 
//next 정보는 호출한 함수에서 실행
void EmpInfo(Value value);

//List fuction
void ListInit(List * list, Comp comp);
void LInsert(List * list, int key, char * name);
Value LFirst(List * list);
Value LNext(List * list);
Value LRemove(List * list);

//table function
void TableInit(Table * table, int len, Hash hash, Comp comp);
int TInsert(Table * table, Key key, char * name);
Value TSearch(Table * table, Key key);
void TDelete(Table * table, Key key);


#endif
