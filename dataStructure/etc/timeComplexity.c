#include<stdio.h>
#include<stdlib.h>

void binarySearch(int arr[], int len, int find){

	int start=0;
	int end=len-1;
	int mid;
	int count=0;

	while(start <= end){
		count++;
		mid=(start+end)/2;
		
		if(find == arr[mid]){
			printf("find, count=%d\n", count);
			return;
		}else {
			//확률이 더 높은 경우가 앞으로 오는 것이 좀 더 유리.
			if(find < arr[mid]){
				end=mid-1;
				continue;
			}else {	//find > arr[mid]
				start=mid+1;
				continue;
			}

		} //else	
	} //while

	printf("실패. count=%d\n", count);
	return;
}
int main(int argc,char * argv[]){

	int find=atoi(argv[1]);

	//모두 0으로 초기화
	int arr1[500]={0,};
	int arr2[5000]={0,};
	int arr3[50000]={0,};

	
	binarySearch(arr1, sizeof(arr1)/sizeof(int),find);
	
	binarySearch(arr2, sizeof(arr2)/sizeof(int),find);

	binarySearch(arr3, sizeof(arr3)/sizeof(int),find);
	
	return 0;
}
