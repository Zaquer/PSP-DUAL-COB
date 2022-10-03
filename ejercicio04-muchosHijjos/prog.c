#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define N_HIJOS 4

int main(int argc, char const *argv[])
{
    pid_t p;
    

    for (int i = 0; i < N_HIJOS; i++)
    {
        p=fork();
        if(p==0){
            printf("soy el hijo del num: %d, %d\n ",i, getpid());
            return i;
        }

    }
    int estado;
    pid_t pid;
    for (int i = 0; i < N_HIJOS; i++)
    {
        pid=wait(&estado);
        printf("Un hijo con pib %d, ha acabado con valor :  %d\n",
        pid,WEXITSTATUS(estado));
    }
    
    return 0;
}