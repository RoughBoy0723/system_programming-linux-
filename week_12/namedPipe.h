#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

struct message{
		char privfifo[15];
		char filename[100];
};

#define SERVER "server"
#define LINESIZE 512
#define NUMTRIES 3
