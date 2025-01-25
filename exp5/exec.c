//Using exec() System Call in Child Process

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        printf("Fork failed!\n");
        return 1;
    }
    else if (pid == 0) {
        // Child process
        printf("Child Process: Executing 'ls -l'\n");
        execl("/bin/ls", "ls", "-l", NULL);
        // If execl() fails
        printf("Execution failed!\n");
    }
    else {
        // Parent process
        printf("Parent Process: Waiting for child to execute 'ls'\n");
        wait(NULL);
        printf("Parent Process: Child execution completed.\n");
    }

    return 0;
}

//output
//Parent Process: Waiting for child to execute 'ls'
//Child Process: Executing 'ls -l'
//(total directory contents listed)
//Parent Process: Child execution completed.
