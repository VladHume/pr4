
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    size_t max = SIZE_MAX;
    printf("SIZE_MAX = %zu\n", max);
    void *ptr = malloc(max);
    if (ptr == NULL)
        perror("malloc");
    else
        free(ptr);
    return 0;
}
