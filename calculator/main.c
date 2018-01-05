#include <stdio.h>
#include "converter.h"
#include "cal.h"
int main(){
	char exp1[]="1+2*3";
	char exp2[]="(1+2)*3";
	char exp3[]="((1-2)+3)*(5-2)";

	printf("%s : ", exp1);
	Convert(exp1);
	printf("%d\n", calculator(exp1));
	printf("%s : ", exp2);
	Convert(exp2);
	printf("%d\n", calculator(exp2));
	printf("%s : ", exp3);
	Convert(exp3);
	printf("%d\n", calculator(exp3));


	return 0;
}
