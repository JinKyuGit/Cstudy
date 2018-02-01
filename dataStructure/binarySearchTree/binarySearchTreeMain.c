#include<stdio.h>
#include<stdlib.h>
#include"binarySearchTree.h"



void ShowData(int data){
	printf("%d ", data);
}

void ShowAll(Tree * tree){
	LeftTraverse(tree, ShowData);
	printf("\n");
}

int main(){

	Tree * root;
	int data;
	int target;	
	int del;
	BTreeInit(&root);
	int count=0;	
	printf(" == 이진 탐색 트리 ==\n");

	//삽입
	while(1){
		printf("삽입할 데이터 입력(종료는 0) : ");
		scanf("%d", &data);

		if(data == 0){
			printf("삽입을 종료합니다.\n");
			break;
		}

		InsertData(&root, data);
		count++;
		ShowAll(root);
	}

	if(count == 0){
		printf("삽입된 데이터가 없어 프로그램을 종료합니다.\n");
		return 0;
	}
		
	
	//탐색
	while(1){
		ShowAll(root);
		printf("탐색할 키값(종료는 0) : ");
		scanf("%d", &target);
		
		if(target == 0){
			printf("탐색을 종료합니다.\n");
			break;
		}

		Tree * temp=SearchData(root, target);
		if(NULL != temp){
			printf("탐색 성공!\n");
			printf("탐색 위치 : %p\n", temp);
		}else {
			printf("탐색 실패\n");
		}

	}


	//삭제
	while(1){
		
		if(count == 0){
			printf("데이터가 전부 삭제되어 프로그램을 종료합니다.\n");
			break;
		}
		ShowAll(root);
		printf("삭제할 키값(종료는 0) : ");
		scanf("%d", &del);

		
		if(del == 0){
			printf("프로그램을 종료합니다.\n");
			break;
		}

		Tree * temp=DeleteData(&root, del);
		
		if(NULL == temp){
			printf("해당 데이터가 없습니다.\n");
		}else {
			printf("삭제 성공.\n");
			printf("삭제한 데이터 : %d\n", GetData(temp));
			free(temp);
			count--;
		}
	}
	return 0;
}
