#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"table.h"
#include"LinkedList.h"


int GetEmpNo(Value value){
	return value->empNo;
}
//사원 등록함수. -> 테이블 슬롯 등록을 통해 사용
Value enrollEmp(int empNo, char * name, char * dept){
	
	//메모리 할당.
	Emp * emp=(Emp *)malloc(sizeof(Emp));
	
	int len1=strlen(name)+1;
	int len2=strlen(dept)+1;
	
	emp->name=(char *)malloc(len1);
	emp->dept=(char *)malloc(len2);
	
	//저장.
	emp->empNo=empNo;
	strcpy(emp->name, name);
	strcpy(emp->dept, dept);
	
	return emp;
}

//사원 정보 출력.
void EmpInfo(Value value){
	
	printf(" == 사원 정보 ==\n");
	printf(" 사번 : %d\n", value->empNo);
	printf(" 이름 : %s\n", value->name);
	printf(" 부서 : %s\n", value->dept);

}

void TableInit(Table * table, int len,Comp comp, Hash hash){

	int i;
	for(i=0; i<len; i++){
		ListInit(table->list[i], comp);
	}

	table->hash=hash;
}

int InsertData(Table * table, Value value){
	
	int idx=table->hash(value->empNo);
	LInsert(table->list[idx], value);

	return idx;
}

value SearchData(Table * table, Key key){

	int idx=table->hash(key);
	
	SLot * slot=NULL;

	slot=LFirst(table->list[idx]);
	
	if(NULL == slot){
		return NULL;
	}

	//같은 해쉬값에 또 있는 경우
	if( (table->list[idx]).numOfData > 1){
		
		//동일한 키값 탐색.
		while(key != slot->value->empNo){
			slot=LNext(table->list[idx]);
		} //while
	}
	
	return slot->value;
}

int DeleteData(Table * table, Key key){

	//아 귀찮다..




}


