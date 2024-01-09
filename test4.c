#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void display_message(int s) {
    printf("TIC ");
    alarm(1);
}

int main(int argc, char *argv[]) {
    signal(SIGALRM, display_message);
    alarm(1);
    while (1) {
        // Do something here
    }
    return 0;
}

