#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<string.h>

#define BUFSIZE 20

main()
{
	int clientSock;
	struct sockaddr_in serverAddr;
	char server_ip[] = "127.0.0.1";
	unsigned short server_port=25051;
	char sendBuf[BUFSIZE];
	printf("\n\tEnter the filename:");
	gets(sendBuf);
	printf("\n\tYou asked for the file:");
	puts(sendBuf);
	bzero(&serverAddr,sizeof(serverAddr));
	serverAddr.sin_family = AF_INET;//Internet Address family
	serverAddr.sin_port = htons(server_port);//Local Port address
	inet_aton(server_ip,(&serverAddr.sin_addr));
	if((clientSock=socket(PF_INET,SOCK_STREAM,0))<0)
	{
		printf("\n\tSocket Error.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Socket Created.\n");
	if((connect(clientSock,(struct sockaddr*)&serverAddr,sizeof(serverAddr)))<0)
  	{
   		printf("\nConnect Error\n");
   		close(clientSock);
   		exit(1);
  	}
  	printf("\n\tCLIENT: Connected.\n");
  	if(write(clientSock,sendBuf,sizeof(sendBuf))<0)
	{
		printf("\n\tSend Error.\n");
		exit(1);
	}
	printf("\n\tCLIENT: Sent.\n");
	close(clientSock);
}
