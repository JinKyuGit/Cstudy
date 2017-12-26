#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>


void error_handling(char * message){
	
		fputs(message, stderr);
		fputc('\n', stderr);
		exit(1);
}

int main(int argc, char * argv[]){

		char * name=argv[3];

		if(argc!=4){
			//ip 및 port 미입력
			printf("Usage : %s <IP> <port> <your name>\n", argv[0]);
			return 0;
		}

		int sock;
		struct sockaddr_in server_addr;

		//소켓 생성
		sock=socket(PF_INET, SOCK_STREAM, 0);

		if(sock == -1){
			error_handling("socket error");
		}
		
		//connect
		memset(&server_addr, 0, sizeof(server_addr));
		server_addr.sin_family=AF_INET;
		server_addr.sin_addr.s_addr=inet_addr(argv[1]);
		server_addr.sin_port=htons(atoi(argv[2]));
	
		if(connect(sock, (struct sockaddr *)&server_addr,
				sizeof(server_addr)) == -1){
				error_handling("connect error");
		}
		
		printf("종료 : /exit\n");
		//chat
		while(1){
			printf("[%s] : ", name);
			char buffer[255];
			fgets(buffer, sizeof(buffer), stdin);
			
			//send
			size_t bufferLen=strlen(buffer);
			ssize_t numBytesSent=send(sock, buffer, bufferLen, 0);
			if(numBytesSent == -1){
				error_handling("send error");
			}

			//break
			if(strncmp(buffer, "/exit", 5) == 0){
				break;
			}
			printf("상대방의 응답을 기다리고 있습니다.....\n");
			//수신
			ssize_t numBytesRcvd=recv(sock, buffer, sizeof(buffer), 0);
			if(numBytesRcvd == -1){
				error_handling("recv error");
			}else if(numBytesRcvd == 0){
				error_handling("connection closed");
			}
			buffer[numBytesRcvd]='\0';

			//출력
			printf("[admin] : %s\n", buffer);

		} //while
		
		close(sock);


		return 0;
}
