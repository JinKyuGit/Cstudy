#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//단순한 수준의 table을 이용한
//사원관리 프로그램 구현.


#define LEN 1000

typedef struct _emp {

	char * name;
	int age;

} Emp;


void InputData(Emp emp[]){

	
	int empNo;
	char name[100];
	int age;

	printf("\n == 사원 등록 ==\n");
	
	printf("사번 입력 : ");
	scanf("%d", &empNo);
	printf("이름 입력 : ");
	scanf("%s", name);
	printf("나이 입력 : ");
	scanf("%d", &age);


	emp[empNo].name=(char *)malloc(strlen(name)+1);
	strcpy(emp[empNo].name, name);
	
	emp[empNo].age=age;
	
	printf("사원 등록이 완료되었습니다.\n");
}


void ShowData(Emp emp[]){

	printf("\n = 사원 정보 출력 =\n");
	
	int empNo;

	printf("사번 입력 : ");
	scanf("%d", &empNo);
	

	if(emp[empNo].age == 0){
		
		printf("해당 사번의 사원은 없습니다.\n");
		return;
	}

	printf(" -이름 : %s\n", emp[empNo].name);
	printf(" -나이 : %d\n", emp[empNo].age);

}

void ShowMenu(){

	printf("\n == 사원 관리 프로그램 == \n");
	printf("1. 사원 등록\n");
	printf("2. 사원 정보 확인\n");

}



int main(){

	Emp emp[LEN];//emp의 index가 key가 된다.
	Emp temp;
	
	int choice;

	while(1){
		
		ShowMenu();
		printf("선택(종료는 0) : ");
		scanf("%d", &choice);

		if(choice == 1){
			InputData(emp);		
		}else if(choice == 2){
			ShowData(emp);
		}else {
			break;
		}


	}

	printf("프로그램을 종료합니다.\n");
	return 0;
}
