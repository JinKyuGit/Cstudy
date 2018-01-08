#include<stdio.h>


//삽입정렬
// 시간복잡도 O(n제곱)



int main(){

	int arr[5]={3, 5, 2, 6, 1};
	int i, j;
	int temp;
	int len=sizeof(arr)/sizeof(int);

	printf("정렬 전 : ");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	//첫번째 요소는 정렬되었다고 가정.
	//두번째부터 한칸씩 앞으로 이동하면서
	//비교 > 값이 작거나 큰 경우 복사
	//반대의 경우 그자리에 삽입.
	for(i=1; i<len; i++){
		temp=arr[i];
		for(j=i; j>0; j--){
			if(arr[j-1] > temp){
				arr[j]=arr[j-1];
			}else {
				break;
			}
		}
		arr[j]=temp;
	}

	printf("정렬 후 : ");
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}
