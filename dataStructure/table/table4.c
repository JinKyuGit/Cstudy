#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"table4.h"


int GetHash(Key key){
	return key % 100;
}


int main(){

	
	Table table;	
	int idx;
	Emp * emp;
	Emp * search;
	int result;

	TableInit(&table, MAX, GetHash);

	emp=enrollEmp(20180001, "Lee", "NULL");
	
	idx=InsertData(&table, emp);
	
	printf("저장 idx : %d\n", idx);


	search=SearchData(&table, 20180001);
	
	if(NULL!= search){
		EmpInfo(search);
	}else {
		printf("search failed\n");
	}

	result=DeleteData(&table, 20180001);

	if(result == 1){
		printf("delete success\n");
	}else {
		printf("delete failed\n");
	}	



	return 0;
}


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

//테이를 초기화
void TableInit(Table * table, int len, Hash hash){

	int i;
	for(i=0; i<len; i++){
		(table->slot[i]).status=EMPTY;
	}
	
	table->hash=hash;

}

//테이블에 데이터 저장. 저장한 슬롯넘버 리턴.
int InsertData(Table * table, Value value){
	
	int idx=table->hash(value->empNo);

	(table->slot[idx]).key=value->empNo;
	(table->slot[idx]).value=value;
	(table->slot[idx]).status=INUSE;
	
	return idx;
}

//키값을 통한 검색
Value SearchData(Table * table, Key key){

	int idx=table->hash(key);
	
	if( (table->slot[idx]).status != INUSE ){
			return NULL;
	}

	return (table->slot[idx]).value;

}

//키값을 통한 데이터 삭제.
int DeleteData(Table * table, Key key){
	
	int idx=table->hash(key);
	
	
	if( (table->slot[idx]).status != INUSE ){
			return 0;
	}

	Emp  * emp;
	char * del;
	
	del=((table->slot[idx]).value)->name;
	free(del);
	del=((table->slot[idx]).value)->dept;
	free(del);

	emp=(table->slot[idx]).value;
	free(emp);

	return 1;
}	
