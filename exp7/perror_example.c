#include <stdio.h>
#include <errno.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;

    // Trying to open a non-existent file
    fd = open("non_existent_file.txt", O_RDONLY);
    
    if (fd == -1) {
        perror("File open failed");
        return 1;
    }

    close(fd);
    return 0;
}


//output
//File open failed: No such file or directory
