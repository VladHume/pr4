
#include <stdlib.h>
#include <stdio.h>

int main() {
    for (int i = 0; i < 3; i++) {
        void *ptr = malloc(100);
        if (!ptr) {
            perror("malloc");
            exit(1);
        }
        printf("Using ptr: %p\n", ptr);
        free(ptr);
    }
    return 0;
}
