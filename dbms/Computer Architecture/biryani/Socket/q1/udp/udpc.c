#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<stdlib.h>

#define SERV_PORT 5839
#define MAXLINE 20

int main(int argc,char **argv)
{
	 ssize_t n;
	 struct sockaddr_in servaddr;
	 char sendline[MAXLINE],recvline[MAXLINE];
	 int sockfd;
	 if(argc!=2)
	 {
		 printf("usage:<IPADDRESS>");
		exit(0);
	 }
	 bzero(&servaddr,sizeof(servaddr));
	 servaddr.sin_family=AF_INET;
	 servaddr.sin_port=htons(SERV_PORT);
	 inet_pton(AF_INET,argv[1],&servaddr.sin_addr);
	 sockfd=socket(AF_INET,SOCK_DGRAM,0);
	 printf("enter the data to be send");

	 while(fgets(sendline,MAXLINE,stdin)!=NULL)
	 {
		 sendto(sockfd,sendline,strlen(sendline),0,(struct
		sockaddr*)&servaddr,sizeof(servaddr));
		 printf("line sent");
		n=recvfrom(sockfd,recvline,MAXLINE,0,NULL,NULL);
		recvline[n]='\0';
		fputs(recvline,stdout);
		printf("\n reverse of the sentense is %s",recvline);
		printf("\n");
	 }
 	exit(0);
}
