#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"table3.h"

//해쉬함수
int GetHash(int empNo){
	return empNo % 100;
}


int main(){

	
	Table table;
	
	Emp * new;
	Emp * del;
	int key;

	TableInit(&table, MAX, GetHash);
	new=InsertEmp(20180001, "Lee", 30);
//	EmpInfo(new);
	
	key=InsertData(&table, new);
	printf("key : %d\n", key);
	
	Search(&table, key);

	del=DeleteData(&table, key);
	EmpInfo(del);
	free(del);
	


	return 0;
}


int GetEmpNo(Emp * emp){
	return emp->empNo;
}

//사원 등록.
Emp * InsertEmp(int empNo, char * name, int age){

	Emp * emp=(Emp *)malloc(sizeof(Emp));

	int len=strlen(name)+1;

	emp->name=(char *)malloc(len);
	
	emp->empNo=empNo;
	strcpy(emp->name, name);
	emp->age=age;

	return emp;
}

//사원 정보 출력
void EmpInfo(Emp * emp){

	printf(" == 사원 정보 출력 ==\n");
	printf(" 사번 : %d\n", emp->empNo);
	printf(" 이름 : %s\n", emp->name);
	printf(" 나이 : %d\n", emp->age);
	
}

//테이블 초기화 - 슬롯 초기화 및 함수등록
void TableInit(Table * table, int size, Hash * hash){

	int i;

	for(i=0; i<size; i++){
		(table->tbl[i]).status=EMPTY;
	}
	
	table->hash=hash;

}

//테이블에 데이터 삽입
Key InsertData(Table * table, Value value){
	
	int empNo=value->empNo;
	int key=table->hash(empNo);
	(table->tbl[key]).value=value;
	(table->tbl[key]).key=key;
	(table->tbl[key]).status=INUSE;

	return key;
}

//키값을 통한 데이터 삭제.
Value DeleteData(Table * table, int key){
	(table->tbl[key]).status=DELETED;
	(table->tbl[key]).key=0;
	return (table->tbl[key]).value;
}

//키값을 통한 데이터 검색.
void Search(Table * table, int key){
	
	EmpInfo((table->tbl[key]).value);

}
