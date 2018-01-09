#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//각 정렬 별로 성능 계산기 작성.

int main(int argc, char * argv[]){

	if(argc != 2){
		printf("Usage : %s <size of Array>\n", argv[0]);
		return 0;
	}

	//입력받은 크기만큼 배열 생성.
	int n=atoi(argv[1]);
	printf("n : %d\n", n);
	int * arr=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr1=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr2=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr3=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr4=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr5=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr6=(int *)malloc(sizeof(n)*sizeof(int));
	int * arr7=(int *)malloc(sizeof(n)*sizeof(int));

	//배열에 랜덤값 넣기.
	srand((int)time(NULL));
	int i;
	for(i=0; i<n; i++){
		arr[i]=(rand()% n)+1;
		arr1[i]=arr[i];
		arr2[i]=arr[i];
		arr3[i]=arr[i];
		arr4[i]=arr[i];
		arr5[i]=arr[i];
		arr6[i]=arr[i];
		arr7[i]=arr[i];
	}

	//시간 계산 변수.
	time_t start, end;
	double gap;

	start=clock();
	end=clock();
	gap=(double)(end-start)/(double)1000;

	//정렬 성능 비교


	return 0;
}
