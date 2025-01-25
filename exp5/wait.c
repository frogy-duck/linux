//Using wait() to Ensure Parent Waits for Child

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        sleep(2);
        printf("Child Process Exiting...\n");
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d, waiting for child...\n", getpid());
        wait(NULL); // Parent waits for child to finish
        printf("Parent Process: Child has finished.\n");
    }

    return 0;
}
