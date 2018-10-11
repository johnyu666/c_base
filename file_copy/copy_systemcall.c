#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[]){
	char *source=argv[1];
	char *target=argv[2];
	int bufSize=atoi(argv[3]);
	int in,out,len;
	char buf[bufSize];
	in=open(source,O_RDONLY);
	out=open(target,O_CREAT|O_WRONLY,S_IRUSR);
	while((len=read(in,buf,bufSize))!=0){
		write(out,buf,len);
	}
	close(in);
	close(out);
}

