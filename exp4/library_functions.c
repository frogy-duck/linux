#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    printf("Enter a string: ");
    scanf("%s", str);

    printf("Length of string '%s' is: %lu\n", str, strlen(str));

    return 0;
}


//gcc library_functions.c -o library_functions
// ./library_functions
