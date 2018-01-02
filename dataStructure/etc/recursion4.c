#include<stdio.h>


void hanoi(int num, char from, char by, char to){
	
	if(num==1){
		printf("남은 원반 1개를 %c에서 %c로 이동\n", from, to);
		//마지막 남은 원반 1개를 이동시키는 것
		return;
	}else {
		hanoi(num-1, from, to, by);
		//우선 A에서 C를 이용하여 B로 이동
		printf("%d를 %c에서 %c로 이동\n", num, from, to);
		hanoi(num-1, by, from ,to);
		//그다음 B에서 A를 이용해서 C로 이동.
	}

}


int main(){

	hanoi(3, 'A', 'B', 'C');

	return 0;
}
