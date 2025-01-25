#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int pipe_fd[2];  // File descriptors for the pipe
    pid_t pid;
    char write_msg[] = "Hello from Parent!";
    char read_msg[100];

    // Create a pipe
    if (pipe(pipe_fd) == -1) {
        perror("Pipe creation failed");
        return 1;
    }

    // Fork to create child process
    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {  // Child process
        close(pipe_fd[1]);  // Close the write end of the pipe

        // Read data from pipe
        read(pipe_fd[0], read_msg, sizeof(read_msg));
        printf("Child Process Received: %s\n", read_msg);

        close(pipe_fd[0]);  // Close the read end
    } else {  // Parent process
        close(pipe_fd[0]);  // Close the read end of the pipe

        // Write data to pipe
        write(pipe_fd[1], write_msg, strlen(write_msg) + 1);
        printf("Parent Process Sent: %s\n", write_msg);

        close(pipe_fd[1]);  // Close the write end
    }

    return 0;
}


//output
//Parent Process Sent: Hello from Parent!
//Child Process Received: Hello from Parent!
