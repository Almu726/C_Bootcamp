#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

void sigstuff (int sig);

int main(void) {
    signal(SIGUSR1, sigstuff);
    pid_t pid1, pid2, pid3;

    printf("Parent started. PID = %d\n", getpid());

    // First child
    pid1 = fork();

    if (pid1 < 0) {
        perror("fork");
        return 1;
    }

    if (pid1 == 0) {
        // Child 1
        while (1) {
            printf("Child Node 0 Killed\n");
            exit(EXIT_SUCCESS);
        }
    }

    pid3 = fork();
    if (pid3 == 0){
        while(1) {
            printf("Child Node 1 Made\n");
            sleep(1);
        }
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("fork");
        return 1;
    }

    if (pid2 == 0) {
        // Child 2
        while (1) {
            printf("Child Node 2 Made\n");
            sleep(1);

            
        }
    }



    sleep(6);
    kill(pid2, SIGUSR1);
    kill(pid3, SIGUSR1);





    return 0;
}


void sigstuff (int sig){
    printf("Signal recieved\n");


    int curr_pid = getpid();
    printf("pid: %d recieved sig %d, from my parent %d\n",curr_pid, sig, getppid());
    exit(EXIT_SUCCESS);
    
}




