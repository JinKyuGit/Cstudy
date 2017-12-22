#include<stdio.h>
#include<string.h>


//읽기
void fileRead(char * filePath){
	
	printf("선택한 파일명 : %s\n", filePath);
	FILE * file=fopen(filePath, "rt");

	if(NULL==file){
		puts("file open failed\n");
		return;
	}
	int ch;

	while(1){
		ch=fgetc(file);
		if(ch==EOF){
			break;
		}	

		printf("%c", ch);
	}
	printf("\n");
	fclose(file);
}



//쓰기
void fileWrite(char * filePath){
	
	printf("선택한 파일명 : %s\n", filePath);
	
	FILE * file=fopen(filePath, "wt");

	if(NULL==file){
		puts("file open failed\n");
	}
	
	//버퍼 비우기
	while(getchar()!='\n');

	char ch[100];
	printf("쓸 내용을 작성하세요.\n");
	fgets(ch, sizeof(ch), stdin);

	fputs(ch, file);

	fclose(file);



}

int main(void){

	//파일 읽고 쓰기
	
	
	char fileName[20];
	//문자열 덧붙이기 - strcat
	
	while(1){

		int choice;
		char filePath[50]="/home/jinkyu/Desktop/";
		printf("읽기 1 쓰기 2 종료 3 : ");
		scanf("%d", &choice);
		if(choice==1 || choice==2){
			printf("읽거나 쓸 파일명 : ");
			scanf("%s", fileName);
			//파일경로 설정
			strcat(filePath, fileName);

		if(choice==1){
			//읽기
			fileRead(filePath);
		} else if(choice==2){
			//쓰기	
			fileWrite(filePath);
		}

		}else {
			break;
		}

		
	}

		return 0;
}
