#include    <unistd.h>
#include    <sys/wait.h>
#include    <stdio.h>
#include    <stdlib.h>

void main(int argc, char* argv[]){
    if(argc <= 1){
        printf("usage: %s #NUMCHILDS", argv[0]);
        exit(0);
    }

    long MAX_INT = 10000000000;

    int num_childs = atoi(argv[1]);
    if(num_childs <= 0){
        printf("usage: %s #NUMCHILDS", argv[0]);
        printf("          #NUMCHILDS must be greater than 0");
        exit(0);
    }
    printf("launching %d childs loops\n", num_childs);

    int wstatus;
    for(int i=0; i<num_childs; i++){
        int pid = fork();
        if( 0 == pid){
            printf("  Starting child %d\n", i);
            long acum = 0;
            for(long i=0; i<MAX_INT; i++){
                acum += 1;
            }
            sleep(i);
            printf("  End of child %d\n", i);
            exit(0);
        } else {
            printf("Started child %d\n", pid);
        }
    }
    sleep(1);
    if(1 == num_childs){
        printf("Waiting for child\n");
    } else {
        printf("Waiting for children\n");
    }
    for(int wcont=0; wcont<num_childs; wcont++){
        int chpid = wait(&wstatus);
        printf("Child %d exited\n", chpid);
    }
    exit(0);
}