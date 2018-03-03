#include<stdio.h>
#include"graph.h"
#include<string.h>
#include<stdlib.h>

int main(){


	Graph graph;

	GraphInit(&graph, MAX);
	
	int choice;
	int from;
	int to;
	while(1){
		printf("\n == 그래프 프로그램 ==\n");
		printf("1. 데이터 추가\n");
		printf("2. 데이터 출력\n");
		printf("3. 종료\n");
		printf("선택 : ");
		scanf("%d", &choice);
		
		if(choice == 3){
			printf("프로그램을 종료합니다.\n");
			break;
		}

		switch(choice){
			case 1:
				printf("from 입력(0~6) : ");
				scanf("%d", &from);
				printf("to 입력(0~6) : ");
				scanf("%d", &to);
				GInsert(&graph, from, to);
				break;
			case 2:
				ShowInfo(&graph);
				break;
		} //switch
	} //while
	



	return 0;
}
