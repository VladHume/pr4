#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(0);
    if (!ptr) {
        printf("malloc(0) returned NULL\n");
    } else {
        printf("malloc(0) returned %p\n", ptr);
        free(ptr);  // все одно безпечно
    }
    return 0;
}
