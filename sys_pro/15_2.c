#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
    int fd1;
    char buf;

    fd1 = open(argv[1], O_RDONLY);

    lseek(fd1,atol(argv[2]) ,lseek_set);
    write(fd1, argv[3], strlen(argv[3]));

    close(fd1);
}