#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>

int main() {
    FILE *fp;

    // Trying to open a non-existent file
    fp = fopen("non_existent_file.txt", "r");
    
    if (fp == NULL) {
        printf("Error opening file! Errno: %d\n", errno);
        printf("Error message: %s\n", strerror(errno));
        return 1;
    }

    fclose(fp);
    return 0;
}


//Error opening file! Errno: 2
//Error message: No such file or directory
