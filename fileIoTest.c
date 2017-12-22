#include<stdio.h>


int main(void){
	

	FILE * fp=fopen("/home/jinkyu/Desktop/test1", "wt");

	if(fp==NULL){
		puts("file open failed\n");
		return -1;
	}

	fputc('A', fp);
	fputc('B', fp);

	fclose(fp);

	return 0;
}
