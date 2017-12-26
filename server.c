#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<time.h>


void error_handling(char * message){

	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}

int main(int argc, char * argv[]){

	if(argc!=2){
		//포트번호 미입력.
		printf("Usage : %s <port>\n", argv[0]);
		return 0;
	}
		
	int client_socket;
	int server_socket;
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	socklen_t client_addr_size=sizeof(client_addr);

	
	//소켓 생성
	server_socket=socket(PF_INET, SOCK_STREAM, 0);

	if(server_socket == -1){
		error_handling("socket error");
	}
	
	//bind
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family=AF_INET;
	server_addr.sin_addr.s_addr=htonl(INADDR_ANY);
	server_addr.sin_port=htons(atoi(argv[1]));

	if(bind(server_socket, (struct sockaddr *)&server_addr,
				sizeof(server_addr)) == -1) {
		error_handling("bind error");
	}

	//listen
	if(listen(server_socket, 5) == -1){
		error_handling("listen error");
	}

	//accept
	client_socket=accept(server_socket, (struct sockaddr *)&client_addr,
			&client_addr_size);
	if(client_socket == -1){
		error_handling("accept error");
	}

	
	//클라이언트 정보 확인
	printf("%s(%d) 접속\n", inet_ntoa(client_addr.sin_addr),
			ntohs(client_addr.sin_port));

	//chat
	while(1) {
	//클라이언트의 메세지 수신
	printf("상대방의 응답을 기다리고 있습니다.....\n");
	char buffer[255];
	ssize_t numBytesRcvd=recv(client_socket, buffer, sizeof(buffer), 0);	
	if(numBytesRcvd == -1){
		error_handling("recv error");
	}else if(numBytesRcvd == 0){
		error_handling("connection closed");
	}
	buffer[numBytesRcvd]='\0';
	
	//종료 조건
	if(strncmp(buffer,"/exit", 5) == 0){
		break;
	}
	//출력
	printf("[%s(%d)] : %s\n", inet_ntoa(client_addr.sin_addr),
			ntohs(client_addr.sin_port), buffer);

	//전송할 메시지 작성
	printf("[admin] : ");
	fgets(buffer, sizeof(buffer), stdin);
	
	//문자열 계산 결과를 클라이언트에게 전송
	size_t bufferLen=strlen(buffer);
	ssize_t numBytesSent=send(client_socket, buffer, bufferLen, 0);
	if(numBytesSent == -1){
		error_handling("send error");
	}

	} //while


	close(client_socket);
	close(server_socket);

	return 0;
}
