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
        // Child process executes 'ls -l'
        printf("Child Process (PID: %d) executing 'ls -l'\n", getpid());
        execl("/bin/ls", "ls", "-l", NULL);
        printf("This will not be printed if exec() is successful.\n");
    }
    else {
        // Parent process waits for the child
        printf("Parent Process (PID: %d) waiting for child (PID: %d)\n", getpid(), pid);
        wait(NULL);
        printf("Parent Process: Child has completed execution.\n");
    }

    return 0;
}



//Output
//Parent Process (PID: 12345) waiting for child (PID: 12346)
//Child Process (PID: 12346) executing 'ls -l'
//(total directory listing displayed)
//Parent Process: Child has completed execution.
