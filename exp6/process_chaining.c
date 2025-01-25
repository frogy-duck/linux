#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Before exec(), PID: %d\n", getpid());

    // Replace the current process with a new one (e.g., ls -l)
    execl("/bin/ls", "ls", "-l", NULL);

    // If execl() fails, this message will be printed
    printf("This will not be printed if exec() is successful.\n");

    return 0;
}


//output
//Before exec(), PID: 12345
//(total directory listing displayed)
