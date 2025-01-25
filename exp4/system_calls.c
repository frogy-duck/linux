#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int file = open("output.txt", O_WRONLY | O_CREAT, 0644);

    if (file < 0) {
        perror("Error opening file");
        return 1;
    }

    char message[] = "Hello, this is written using system calls!\n";
    write(file, message, sizeof(message));

    close(file);
    printf("Message written to output.txt successfully.\n");
    return 0;
}


//gcc system_calls.c -o system_calls
// ./system_calls
