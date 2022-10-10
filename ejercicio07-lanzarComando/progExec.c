#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>

int main(int argc, char const *argv[])
{
    char *parametros[]={"firefox","https://educa.aragon.es","https://google.es"};

    fprintf(stdout,"Mi pid: %d\n",getpid());
    //execl("/usr/bin/firefox","firefox","https://educa.aragon.es");
    execv("/usr/bin/firefox",parametros);
    return 0;
}
