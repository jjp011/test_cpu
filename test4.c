#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void display_message(int s) {

    static int numTicks = 0;

    numTicks ++;
    printf("TIC %d\n", numTicks);
    alarm(1);
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, display_message);
    alarm(1);

    long int MAXCOUNT = 1000000000000;
    long int cont = 0;
    for(long int i = 0; i < MAXCOUNT ; i++) {
        cont ++;
        if(i%1000000000 == 0){
            printf("%10ld\n", cont);
        }
    }
    return 0;
}

