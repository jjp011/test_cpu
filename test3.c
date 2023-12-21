#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *child(void *arg){
    long MAX_INT = 10000000000;
    long acum = 0;
    int id = *(int*)arg;
    printf("Starting child %d\n", id);
    for(long i=0; i<MAX_INT; i++){
        acum += 1;
    }
    sleep(id);
    printf("End of child %d\n", id);
    return NULL;
}

int main(int argc, char* argv[]){
    if(argc <= 1){
        printf("usage: %s #NUMCHILDS", argv[0]);
        exit(0);
    }

    int num_childs = atoi(argv[1]);
    if(num_childs <= 0){
        printf("usage: %s #NUMCHILDS", argv[0]);
        printf("          #NUMCHILDS must be greater than 0");
        exit(0);
    }
    printf("launching %d childs loops\n", num_childs);

    pthread_t threads[num_childs];
    int ids[num_childs];
    for(int i=0; i<num_childs; i++){
        ids[i] = i;
        pthread_create(&threads[i], NULL, child, &ids[i]);
        printf("Started child %d\n", i);
    }
    sleep(1);
    if(1 == num_childs){
        printf("Waiting for child\n");
    } else {
        printf("Waiting for children\n");
    }
    for(int i=0; i<num_childs; i++){
        pthread_join(threads[i], NULL);
        printf("Child %d exited\n", i);
    }
    exit(0);
}
