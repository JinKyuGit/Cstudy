#include<stdio.h>

//간단한 해쉬함수를 이용한 사원 관리 프로그램.
//해쉬 : 넓은 범위의 key를 좁은 범위의 key로 변환하는 것.



typedef struct _emp {

	int empNo;
	int age;

} Emp;


int GetHash(int empNo){

	return empNo % 100;
}

void ShowInfo(Emp emp[], int key){

	printf("사번 : %d\n", emp[key].empNo);
	printf("나이 : %d\n", emp[key].age);

}


int main(){

	//hash값이 중복되지 않도록
	//사번은 연도 + 고유 인덱스
	
	Emp empArr[100];

	Emp emp1={20180001, 19};
	Emp emp2={20180002, 20};

	int key1=GetHash(emp1.empNo);
	int key2=GetHash(emp2.empNo);
	
	printf("key 1 : %d\n", key1);
	printf("key 2 : %d\n", key2);


	empArr[key1]=emp1;
	empArr[key2]=emp2;

	
	ShowInfo(empArr, key1);
	ShowInfo(empArr, key2);
	




	return 0;
}
