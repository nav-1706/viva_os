#include <stdio.h>
#include <pthread.h>

#define NUM_LOOPS 5

int turn = 0;
int flag[2] = {0};

void* process0(void* arg) {
    int i;

    for (i = 0; i < NUM_LOOPS; i++) {
        flag[0] = 1;
        while (flag[1]) {
            if (turn == 1) {
                flag[0] = 0;
                while (turn == 1)
                    ;
                flag[0] = 1;
            }
        }

        // Critical section for process 0
        printf("Process 0 is in critical section (loop %d).\n", i + 1);
        turn = 1;
        flag[0] = 0;
    }

    pthread_exit(NULL);
}

void* process1(void* arg) {
    int i;

    for (i = 0; i < NUM_LOOPS; i++) {
        flag[1] = 1;
        while (flag[0]) {
            if (turn == 0) {
                flag[1] = 0;
                while (turn == 0)
                    ;
                flag[1] = 1;
            }
        }

        // Critical section for process 1
        printf("Process 1 is in critical section (loop %d).\n", i + 1);
        turn = 0;
        flag[1] = 0;
    }

    pthread_exit(NULL);
}

int main() {
    pthread_t threads[2];

    pthread_create(&threads[0], NULL, process0, NULL);
    pthread_create(&threads[1], NULL, process1, NULL);

    pthread_join(threads[0], NULL);
    pthread_join(threads[1], NULL);

    return 0;
}
