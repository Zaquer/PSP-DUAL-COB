#include<stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include<unistd.h>

int main(int argc, char const *argv[])
{
    
    fprintf(stdout,"Mi pid: %d\n",getpid());
    system("ls -l > ls.txt");
    system("ls -l");
    system("firefox https://educa.aragon.es");

    return 0;
}

