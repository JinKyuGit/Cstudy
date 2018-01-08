#include<stdio.h>



//선택정렬
//시간 복잡도 비교연산 O(n제곱)
//이동연산 O(n)



int main(){

	
	int arr[5]={5, 4, 2, 1, 3};
	int i, j;
	int temp;
	int len=sizeof(arr)/sizeof(int);


	printf("정렬 전 : ");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	

	//특정 인덱스 값을
	//나머지 인덱스들과 하나하나 비교 및 교환하여
	//맨 앞 또는 맨 뒤부터 정렬해나간다.
	for(i=0; i<len-1; i++){
		for(j=i+1; j<len; j++){
			if(arr[i]>arr[j]){
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}



	printf("정렬 후 : ");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
