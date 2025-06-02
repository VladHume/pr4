#include <stdio.h>
#include <stdlib.h>

int main() {
    int xa = 1 << 30;  // 2^30
    int xb = 8;        // 8
    int num = xa * xb; // integer overflow!

    printf("xa=%d, xb=%d, num=%d\n", xa, xb, num);

    void *ptr = malloc(num);
    if (!ptr) perror("malloc");
    else free(ptr);
    return 0;
}
