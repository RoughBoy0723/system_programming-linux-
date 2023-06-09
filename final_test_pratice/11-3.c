#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[]){
    int fd[2];
    pipe(fd);
    char msg[512];

    if(fork()==0){
        close(1);
        dup(fd[1]);
        close(fd[0]);
        close(fd[1]);
        execl(argv[1],argv[1],(char*)0);
    }
    if(fork()==0){
        close(0);
        dup(fd[0]);
        close(fd[0]);
        close(fd[1]);
        read(0,msg,512);
        puts(msg);
    }
    while(wait((int *)0) != -1)
        ;
    close(fd[0]);
    close(fd[1]);
    exit(0);
}
