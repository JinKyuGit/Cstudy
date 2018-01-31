#include<stdio.h>
#include"table.h"

int GetHash(int key){
	return key % 100;
}

int Compare(int a, int b){
	
	if(a<=b){
		return 0;	
	}else {
		return 1;
	}
}


int main(){

	
	Table table;
	TableInit(&table, MAX, GetHash, Compare);
	
	int empNo;
	char name[100];
	int choice;
	Emp * emp;
	int idx;

	while(1){
		printf("\n == 사원 관리 프로그램 ==\n");
		printf("1. 사원 등록\n");
		printf("2. 사원 찾기\n");
		printf("3. 사원 삭제\n");
		printf("0. 종료\n");
		printf(" 입력 : ");
		scanf("%d", &choice);

		if(choice == 0){
			break;
		}

		switch(choice){
			case 1:
				printf("사번 입력 : ");
				scanf("%d", &empNo);
				printf("이름 입력 : ");
				scanf("%s", name);
				
				idx=TInsert(&table, empNo, name);
				if(idx == -1){
					printf("오류 발생.\n");
					return 0;
				}else {
					printf("저장 성공 : %d\n", idx);
				}
					break;
			case 2:
				printf("사번 입력 : ");
				scanf("%d", &empNo);
				emp=TSearch(&table, empNo);
				
				if(NULL == emp){	
					printf("\n그런 사원은 없습니다.\n");
					break;
				}else {
					EmpInfo(emp);
				}
				break;
			case 3:
				printf("사번 입력 : ");
				scanf("%d", &empNo);
				TDelete(&table, empNo);
				printf("삭제 완료\n");
				break;
		} //switch
	} //while

	printf("프로그램을 종료합니다.\n");
	
	return 0;
}
