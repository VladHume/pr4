#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int x, y;
};

int main() {
    struct sbar *ptr, *newptr;

    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) return 1;

    // Замінено на reallocarray (замість realloc)
    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        perror("reallocarray");
        free(ptr);
        return 1;
    }

    printf("Old: %p, New: %p\n", ptr, newptr);
    free(newptr);
    return 0;
}
