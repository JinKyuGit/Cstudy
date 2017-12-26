#include<stdio.h>
#include<string.h>
#include<mysql.h>

#define DB_HOST "localhost"
#define DB_USER "jinkyu"
#define DB_PASS "wlrnqhs1"
#define DB_NAME "test"

typedef struct {
	//test table
	char id[30];
	char passwd[30];
	char name[30];
} USER;

typedef struct {
	//db
	int query_stat;
	MYSQL_RES * sql_result;
	MYSQL_ROW sql_row;

} DB;

//메뉴
int menu(){

	int choice;

	printf("=== menu ===\n");
	printf("1. select\n");
	printf("2. insert\n");
	printf("3. update\n");
	printf("4. delete\n");
	printf("5. exit\n");
	printf("선택 : ");
	scanf("%d", &choice);
		
	return choice;
}

//문자열 개행 제거
void removeEnter(char * ptr){

	ptr[strlen(ptr)-1]='\0';
}

//select
void selectQuery(MYSQL * connection, MYSQL conn){

	DB db;
	DB * ptr=&db;

	ptr->query_stat=mysql_query(connection, "select * from user");
	if(ptr->query_stat!=0){
		fprintf(stderr, "query error : %s\n", mysql_error(&conn));
	}

	ptr->sql_result=mysql_store_result(connection);
	while((ptr->sql_row=mysql_fetch_row(ptr->sql_result))!=NULL)
		printf("%s %s %s\n", ptr->sql_row[0], 
				ptr->sql_row[1], ptr->sql_row[2]);

	mysql_free_result(ptr->sql_result);

}

//insert
void insertQuery(MYSQL * connection, MYSQL conn){

	while(getchar()!='\n');
	//개행 제거
	USER user;
	DB db;
	USER * uptr=&user;
	DB * dptr=&db;

	char query[255];


	printf("아이디 : ");
	fgets(uptr->id, sizeof(uptr->id), stdin);
	removeEnter(uptr->id);

	printf("비밀번호 : ");
	fgets(uptr->passwd, sizeof(uptr->passwd), stdin);
	removeEnter(uptr->passwd);

	printf("이름 : ");
	fgets(uptr->name, sizeof(uptr->name), stdin);
	removeEnter(uptr->name);

	sprintf(query, "insert into user values('%s', '%s', '%s')",
			uptr->id, uptr->passwd, uptr->name);

	dptr->query_stat=mysql_query(connection, query);
	if(dptr->query_stat!=0){
		fprintf(stderr, "query error : %s\n", mysql_error(&conn));
		return;
	}else {
		printf("insert success\n");
	}

	mysql_free_result(dptr->sql_result);

}

int main(){

	MYSQL * connection=NULL;
	MYSQL conn;

	while(1){
	int choice=menu();
	
	if(choice==5)
		break;
	else {
		//메뉴 선택시마다 연결
		//더블포인터를 사용해서 함수로 이용하고싶은데
		//방법을 찾아볼것.
		mysql_init(&conn);
		connection=mysql_real_connect(&conn, DB_HOST,
				DB_USER, DB_PASS, DB_NAME, 3306, (char *)NULL, 0);		if(connection == NULL){
			fprintf(stderr, "connection error : %s\n",
				mysql_error(&conn));					
			return 0;
		}


		if(choice==1){
			selectQuery(connection, conn);
		}else if(choice==2){
			insertQuery(connection, conn);
		}
			mysql_close(connection);
			//연결해제
	} //else
   } //while




	return 0;
}

