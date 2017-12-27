#include<stdio.h>


int main(void){

	FILE * fp=fopen("/home/jinkyu/Desktop/test1", "rt");

	if(NULL==fp){
		puts("file open failed\n");
		return -1;
	}
	int ch;
	while(1){
		ch=fgetc(fp);
		if(ch==EOF)
			break;

		printf("%c", ch);
	}

	puts("");
	
	fclose(fp);

	return 0;
}
