#include<stdio.h>
#include<stdlib.h>
#include<time.h>


int main(){

	int arr[10];
	int i, j;

	srand((int)time(NULL));

	int length=sizeof(arr)/sizeof(int);
	//init
	printf("before sort ==========\n");
	for(i=0; i<length; i++){
		arr[i]=(rand () % 100)+1;
		printf("%d ", arr[i]);
	}

	printf("\n");
	
	//sort
	int temp;
	for(i=1; i<length; i++){
		temp=arr[i];
		for(j=i; j>0; j--){
			if(arr[j-1]>temp){
				arr[j]=arr[j-1];
				if(j==1){
					arr[j-1]=temp;
					break;
				}
			} else {
				arr[j]=temp;
				break;
			}
		}
	}

	printf("after sort=============\n");
	for(i=0; i<length; i++){
		printf("%d ", arr[i]);
	}
 	printf("\n");

	return 0;
}
