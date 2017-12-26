#include<stdio.h>
#include<stdlib.h>
#include<time.h>


//난수 중복검사
int check(int * num, int len, int temp){

	int i;
	for(i=0; i<len; i++){
		if(num[i]==temp)
			return 0;
	}

	return 1;
}


//정렬
void sort(int * num){
	int i, j;
	int temp;
	for(i=1; i<6; i++){
		temp=num[i];
		for(j=i; j>0; j--){
			if(num[j-1]>temp){
				num[j]=num[j-1];
				if(j==1){
					num[j-1]=temp;
					break;
				}
			} else {
				num[j]=temp;
				break;
			}
		}
	}
}

int main(){

	puts("=== 로또 번호 생성기===");

	//일주일마다 회차정보 표시 추가할것.
	
	int num[6];
	int temp;
	int count=1;
	srand((int)time(NULL)); // 현재 시간을 이용해 seed 설정
	
	num[0]=(rand()%45)+1;
	int flag;
	while(1){
		
		//번호가 다 모이면 탈출.
		if(count==6){
			break;
		}
		//난수 생성
		temp=(rand()%45)+1;
		//이미 생성된 난수와 겹치는지 확인.
		flag=check(num, count, temp);
		if(flag==0){
			continue;
		}else {
			num[count]=temp;
			count++;
		}
	}
	
	//정렬
	sort(num);

	printf("로또 번호 : ");
	int i;
	for(i=0; i<6; i++){
		printf("%d ", num[i]);
	}
	printf("\n");

	return 0;
}
