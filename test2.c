#include    <unistd.h>
#include    <sys/wait.h>
#include    <stdio.h>

void main(){
    int pid = fork();
    int wstatus;

    if( 0 == pid){
        long MAX_INT = 100000000000;
        long acum = 0;
        for(long i=0; i<MAX_INT; i++){
            acum += 1;
        }
    } else {
        printf("Waiting for child\n");
    }
    wait(&wstatus);
}