#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/select.h>

int main(){

        int n,ret,fds,fds1;
        fd_set set,rdset;
        char sendline[1024],receiveline[1024];

	mkfifo("fifo1",0666);
	mkfifo("fifo2",0666);

        fds=open("fifo1",O_WRONLY);
	fds1=open("fifo2",O_RDONLY);

        FD_ZERO(&set);

	while(1){
		
        	FD_SET(0,&set);
		FD_SET(fds1,&set);
        	ret=select(fds1+1,&set,NULL,NULL,NULL);

        	if(ret<0){
                	printf("error in select system call\n");
                	return;
        	}else{
			if(FD_ISSET(0,&set)){
				fgets(sendline,1024,stdin);
				write(fds,sendline,1024);
			}
			if(FD_ISSET(fds1,&set)){
				n=read(fds1,receiveline,1024);
				printf("%s\n",receiveline);
                        }
       	 	}
	}
        return 0;
}


