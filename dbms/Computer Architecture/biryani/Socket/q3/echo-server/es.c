#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/time.h>
#include <sys/select.h>

int main(){

        int n,ret,fds,fds1,fd;
	struct timeval tv;
        fd_set set;
        char sendline[1024],receiveline[1024];

	tv.tv_sec=2;
	tv.tv_usec=0;

        fds=open("fifo1",O_RDONLY);
	fds1=open("fifo2",O_WRONLY);	

        FD_ZERO(&set);
	
        while(1){

                FD_SET(fds,&set);
                ret=select(fds+1,&set,NULL,NULL,NULL);
                if(ret<0){
                        printf("error in select system call\n");
                        return;
                }else{
                        if(FD_ISSET(fds,&set)){
				n=read(fds,sendline,1024);	
//                                printf("received:%s",sendline);
				write(fds1,sendline,n);
                        }
                }
        }
        return 0;
}

