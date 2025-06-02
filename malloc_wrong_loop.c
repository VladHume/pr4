#include <stdlib.h>
#include <stdio.h>

int main() {
    void *ptr = NULL;
    for (int i = 0; i < 3; i++) {
        if (!ptr)
            ptr = malloc(100);
        printf("Using ptr: %p\n", ptr);
        free(ptr);  // помилка — після першої ітерації ptr стає dangling
    }
    return 0;
}
