#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"table.h"


//next 노드 연결은 이 함수를 호출한 곳에서 수행.
Value Enroll(int empNo, char * name){

	Emp * emp=(Emp *)malloc(sizeof(Emp));
	int len=strlen(name)+1;
	emp->name=(char *)malloc(len);
	
	emp->empNo=empNo;
	strcpy(emp->name, name);
	
	return emp;
}

void EmpInfo(Value value){

	printf("\n == Info ==\n");
	printf("empNo : %d\n", value->empNo);
	printf("name : %s\n", value->name);

}

void ListInit(List * list, Comp comp){

	(list->numOfData)=0;
	list->head=NULL;
	list->cur=NULL;
	list->before=NULL;
	list->comp=comp;

}

void LInsert(List * list, int key, char * name){
	
	Emp * newEmp=Enroll(key, name);
	newEmp->next=NULL;
	(list->numOfData)++;
	
	if(NULL == list->head){
		list->head=newEmp;	
	}else {
		//쩨자리를 찾아가는 과정 필요.
		Emp * cur=list->head;
		Emp * before=cur;

		while(1){
			//tail에 도착한 경우.
			if(NULL == cur){
				break;
			}

			//자리를 찾은경우
			if(list->comp(newEmp->empNo, cur->empNo) == 0){
				printf("%d, %d\n", newEmp->empNo, cur->empNo);
				break;
			}
			
			before=cur;
			cur=cur->next;

		} // while

		//break 상황에 따른 처리.
		if(NULL == cur){
			before->next=newEmp;
		}else {
			//newEmp의 자리는 before와 cur 사이
			newEmp->next=cur;
			before->next=newEmp;
		}
 	} //else
}


Value LFirst(List * list){
	
	list->cur=list->head;
	return list->cur;
}

Value LNext(List * list){
	
	if(NULL == list->cur->next){
			return NULL;
	}

	list->before=list->cur;
	list->cur=list->cur->next;
	
	return list->cur;
}

Value LRemove(List * list){

	Emp * del=list->cur;
	(list->numOfData)--;

	//다음 노드가 없는 경우. 즉 헤드인 경우.
	if(del == list->head){
	}else {
		//다음 노드가 있는 경우.
		list->before->next=list->cur->next;
	} //else
	
	return del;
}

void TableInit(Table * table, int len, Hash hash, Comp comp){


	int i;
	for(i=0; i<len; i++){
			ListInit(&(table->list[i]), comp);
	}
	table->hash=hash;
}

int TInsert(Table * table, Key key, char * name){

	int idx=table->hash(key);
	int check=(table->list[idx]).numOfData;
	
	LInsert(&(table->list[idx]), key, name);
	
	if( (table->list[idx]).numOfData == check){
		//error
		return -1;
	}
	return idx;
}

Value TSearch(Table * table, Key key){
	
	Emp * search;
	int idx=table->hash(key);
	
	if( (table->list[idx]).numOfData == 0){
		return NULL;
	}
	
	search=LFirst(&table->list[idx]);

	//키값이 안맞는 경우.
	//즉, 노드 탐색필요.
	if(search->empNo != key){
			while(search->empNo != key){
				if(NULL == search){
					//error
					return NULL;
				}

				search=LNext(&(table->list[idx]));
			}
	}

	return search;
}


void TDelete(Table * table, Key key){
	
	Emp * check;
	int idx=table->hash(key);

	if( (table->list[idx]).numOfData == 0){
		printf("error\n");	
		exit(1);
	}

	check=LFirst(&table->list[idx]);

	if(check->empNo != key){
		while(check->empNo !=key){
			
			if(NULL == check){
				printf("error\n");
				exit(1);
			}
			
			check=LNext(&table->list[idx]);
		} // while
	}

	Emp * del=LRemove(&table->list[idx]);
	
	free(del->name);
	free(del);
}
