#include<stdio.h>



int main(){
	

	//2차원 배열 90도로 회전
	//첫번째 규칙 - 이동 전 x좌표 > 이동 후 y좌표
	//두번째 규칙 - 이동 전 x좌표 + 이동 후 y좌표 = 3(배열의끝)

	int arr[4][4];
	int i, j;
	int num=1;

	printf("init==================\n");
	//init
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			arr[i][j]=num;
			num++;
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("first==================\n");
	//회전 1
	int ro1[4][4];

	
	int temp=3;
	
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			ro1[i][j]=arr[temp-j][i];
			printf("%d ", ro1[i][j]);
		}
		printf("\n");
	}

	
	printf("second====================\n");
	//회전 2
	int ro2[4][4];
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			ro2[i][j]=ro1[temp-j][i];
			printf("%d ", ro2[i][j]);
		}
		printf("\n");
	}

	printf("third====================\n");
	//회전 3
	int ro3[4][4];
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			ro3[i][j]=ro2[temp-j][i];
			printf("%d ", ro3[i][j]);
		}
		printf("\n");
	}

	
	printf("fourth====================\n");
	//회전 4
	int ro4[4][4];
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			ro4[i][j]=ro3[temp-j][i];
			printf("%d ", ro4[i][j]);
		}
		printf("\n");
	}


	return 0;
}
