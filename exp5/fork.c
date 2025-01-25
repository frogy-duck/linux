#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    // Create child process using fork()
    pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: PID = %d, Parent PID = %d\n", getpid(), getppid());
    }
    else {
        // Parent process
        printf("Parent Process: PID = %d, Child PID = %d\n", getpid(), pid);
        sleep(1); // Ensure parent is alive while child prints its parent PID
    }

    return 0;
}



//Output
//Parent Process: PID = 12345, Child PID = 12346
//Child Process: PID = 12346, Parent PID = 12345
