#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#define BUFFER_SIZE 255
#define FIFO1 "xxxx1"
#define FIFO2 "xxxx2"
void main(){
	int readfd,writefd;
	char buf[BUFFER_SIZE];
	int len;
	readfd = open(FIFO1,O_RDONLY,0);
	writefd = open(FIFO2,O_WRONLY,0);
	sleep(1);
	len = read(readfd,buf,BUFFER_SIZE);
	printf("child receive:%d\n",len);
	printf("child receive:%s\n",buf);
	bzero(buf,sizeof(buf));
	strcpy(buf,"child_abcd");
	write(writefd,buf,strlen(buf)+1);
	close(readfd);
	close(writefd);
}
