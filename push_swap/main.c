#include <stdio.h>
#include <stdlib.h>

void displayBinary(int num) {
    int i;
    for (i = sizeof(int) * 8 - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    int i;
    for (i = 1; i < argc; i++) {
        int num = atoi(argv[i]);
        displayBinary(num);
    }
    return 0;
}
