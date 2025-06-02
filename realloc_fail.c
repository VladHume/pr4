#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(100);
    if (!ptr) return 1;

    void *newptr = realloc(ptr, SIZE_MAX); // занадто велике значення
    if (!newptr) {
        perror("realloc failed");
        free(ptr);  // важливо не втратити ptr
    } else {
        free(newptr);
    }
    return 0;
}
