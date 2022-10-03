
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include<signal.h>

void tratarSenyal(int num_senyal);

int main(int argc, char const *argv[])
{
    signal(SIGINT,tratarSenyal);
    pid_t p;
    p=fork();
    if(p==0){
        printf("Soy el hijo\n");
        sleep(1);
        kill(getppid(),SIGINT);

    }else{
       
        printf("Padre\n");
        pause();

        pid_t hijoTerminado;
        int estado;
        hijoTerminado=wait(&estado);
        prinf("el hijo %d ha terminado con estado: \n",hijoTerminado,WEXITSTATUS(estado));

    }
    return 0;
}

void tratarSenyal(int num_senyal){
    printf("he recibido la señal: %d\n",
    num_senyal);
}
