#include<stdio.h>


void rotate(int(*ptr1)[4], int(*ptr2)[4]){
	int temp=3;
	int i, j;
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			ptr2[i][j]=ptr1[temp-j][i];
		}
	}
	
}

void printArr(int(*ptr)[4]){
	int i, j;

	printf("=================\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			printf("%d ", ptr[i][j]);
		}
		printf("\n");
	}
}


int main(){

	int arr[4][4];
	int i, j;
	int num=1;
	//init
	printf("init =========\n");
	for(i=0; i<4; i++){
		for(j=0; j<4; j++){
			arr[i][j]=num;
			num++;
		}
	}

	printArr(arr);

	int ro1[4][4];
	rotate(arr, ro1);
	printArr(ro1);
	
	int ro2[4][4];
	rotate(ro1, ro2);
	printArr(ro2);

	int ro3[4][4];
	rotate(ro2, ro3);
	printArr(ro3);

	int ro4[4][4];
	rotate(ro3, ro4);
	printArr(ro4);

	return 0;
}
