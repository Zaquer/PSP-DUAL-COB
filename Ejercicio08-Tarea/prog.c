#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char md5[100] = "md5sum ";
    char sha1[100] = "sha1sum ";
    char sha256[100] = "sha256sum ";
    char sha512[100] = "sha512sum ";
    char salida[50] = " > ";
    char resultadoConcat[100] = " >> ";
    
    
    if(argc < 2){
        printf("No se han introducido parámetros\n");
    }
    else{
        
        for (int i = 1; i <= argc; i++)
        {
            if (fork() == 0)
            {   //" > archivo.hashes"
                strcat(salida, argv[i]);
                strcat(salida, ".hashes");

                //"md5sum archivo > archivo.hashes"
                strcat(md5, argv[i]);
                strcat(md5, salida);
                system(md5);

                //" >> archivo.hashes"
                strcat(resultadoConcat, argv[i]);
                strcat(resultadoConcat, ".hashes");

                //"sha1sum archivo >> archivo.hashes"
                strcat(sha1, argv[i]);
                strcat(sha1, resultadoConcat);
                system(sha1);

                //"sha256sum archivo >> archivo.hashes"    
                strcat(sha256, argv[i]);
                strcat(sha256, resultadoConcat);
                system(sha256);

                //"sha512sum archivo >> archivo.hashes"
                strcat(sha512, argv[i]);
                strcat(sha512, resultadoConcat);
                system(sha512);

                return 0;
            }
        }

        int estado;
        pid_t pidHijo;

        for (int i = 1; i < argc; i++)
        {

            pidHijo = wait(&estado);
            if (WEXITSTATUS(estado) == 0)
            {
                printf("El hijo con PID: %d ha finalizado con éxito \n", pidHijo);
            }
            else
            {
                printf("El hijo con PID: %d ha finalizado con error \n", pidHijo);
            }
        }

        return 0;
    }
}