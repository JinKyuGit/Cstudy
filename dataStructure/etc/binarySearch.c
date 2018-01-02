
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void search(int arr[], int len, int find){

	int start=0;
	int end=len-1;
	int mid;
	int count=0;
	while(start <= end){  // start가 더 큰 경우 찾는 숫자가 없는 것임.
		count++;
		mid=(start+end)/2;

		if(find == arr[mid]){
			printf("탐색 성공 : arr[%d], 시도 횟수 : %d\n", mid, count);
			return;
		}else {
			if(find<arr[mid]){
				end=mid-1;
				//arr[mid]는 이미 위에서 확인하였으므로 -1
				continue;
			}else if(find>arr[mid]){
				start=mid+1;
				//arr[mid]는 이미 위에서 확인하였으므로 +1
				continue;
			}
		}
	} //while
	
	//탐색에 실패하여 루프가 깨진 경우.
	printf("탐색 실패. 시도 횟수 : %d\n", count);
	return;

}


int main(int argc, char * argv[]){

	if(argc!=2){
		printf("Usage : %s <number(1~50)>\n", argv[0]);
		return 0;
	}

	//찾고자 하는 수	
	int find=atoi(argv[1]);

	//배열은 반드시 정렬되어 있어야 함
	int arr[]={1, 3, 5, 12, 16, 18 ,22, 25, 34, 50};
	

	int len=sizeof(arr)/sizeof(int);

	//찾고자 하는 숫자가 범위를 벗어난 경우
	if(find<arr[0] || find>arr[len-1]){
		printf("wrong number\n");
		return 0;
	}
	
	int i;
	for(i=0; i<len; i++){
		printf("%d ", arr[i]);
	}

	printf("\n");
	search(arr, len, find);
	return 0;
}
