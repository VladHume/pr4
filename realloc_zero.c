#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr1 = realloc(NULL, 100); // як malloc(100)
    void *ptr2 = realloc(ptr1, 0);   // як free(ptr1), може повернути NULL або не-NULL

    if (!ptr2)
        printf("realloc(..., 0) returned NULL\n");
    else {
        printf("realloc(..., 0) returned %p\n", ptr2);
        free(ptr2);
    }

    return 0;
}
