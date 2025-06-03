#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr1 = malloc(64); // виділяємо 64 байти
    if (!ptr1) {
        perror("malloc failed");
        return 1;
    }

    printf("First allocation: %p\n", ptr1);

    free(ptr1); // звільняємо

    void *ptr2 = malloc(64); // знову виділяємо 64 байти
    if (!ptr2) {
        perror("malloc failed");
        return 1;
    }

    printf("Second allocation: %p\n", ptr2);

    // Перевірка
    if (ptr1 == ptr2) {
        printf("✅ malloc повернув ту саму адресу після free\n");
    } else {
        printf("❌ malloc повернув іншу адресу\n");
    }

    free(ptr2);
    return 0;
}
