#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(void){
	
	//동적 할당
	//malloc = memory allocation
	//type * ptr=(type *)malloc(sizeof(type));
	//free(ptr);
	

	char * ch;
	int size;
	printf("최대 문자 길이 입력 : ");
	scanf("%d", &size);
	while(getchar()!='\n');
	ch=(char *)malloc(sizeof(char)*(size+1));
	printf("문자 입력 : ");
	fgets(ch, size+1, stdin);
	ch[strlen(ch)]=0;
	printf("입력한 문자 : %s\n", ch);
	//뒤집기
	int i;
	printf("뒤집기 : ");
	for(i=size; i>=0; i--){
		printf("%c", ch[i]);
	}
		

	free(ch);
	printf("\n");
	return 0;
}
