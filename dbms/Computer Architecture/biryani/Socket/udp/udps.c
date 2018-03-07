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
	 int i,j;
	 ssize_t n;
	 char line[MAXLINE],recvline[MAXLINE];
	 struct sockaddr_in servaddr,cliaddr;
	 int sockfd,clilen;
	 sockfd=socket(AF_INET,SOCK_DGRAM,0);
	 bzero(&servaddr,sizeof(servaddr));
	 servaddr.sin_family=AF_INET;
	 servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
	 servaddr.sin_port=htons(SERV_PORT);
	 bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

	 for( ; ; )
	 {
		clilen=sizeof(cliaddr);
		while(1)
		{
			 if((n=recvfrom(sockfd,line,MAXLINE,0,(struct sockaddr*)&cliaddr,&clilen))==0)
				break;
			 printf("\n line received successfully");
 			line[n-1]='\0';
 			j=0;
			for(i=n-2;i>=0;i--)
			 {
				recvline[j++]=line[i];
			 }
			recvline[j]='\0';
			 sendto(sockfd,recvline,n,0,(struct sockaddr*)&cliaddr,clilen);
		}
 	}
}
