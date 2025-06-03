# pr4
## Завдання 4.1: Максимальний обсяг пам'яті malloc(3)

**Пояснення:**
- Тип `size_t` на 64-бітній системі займає 8 байт → 2^64 можливих значень.
- Теоретично, максимальний обсяг памʼяті = `2^64` байт = **16 ексабайтів (EB)**.
- Але реально виділити максимум **8 EB**, бо `size_t` має діапазон `0` до `2^64 - 1`.
- Значення `2^64` неможливо, бо воно виходить за межі діапазону.

**Запустимо[max_malloc.c](https://github.com/VladHume/pr4/blob/main/max_malloc.c):**

![image](https://github.com/user-attachments/assets/32aebd65-07ec-48a4-ad5f-0ee228805ff0)


## Завдання 4.2: Від’ємне значення malloc(3)

**Тестовий випадок [malloc_overflow.c](https://github.com/VladHume/pr4/blob/main/malloc_overflow.c):**

![image](https://github.com/user-attachments/assets/ece4852d-8339-4467-b2ce-71d95ee74ca7)
Маємо:

- 1073741824 * 8 = 8589934592, тобто більше ніж 2^31

- Тип int — 32-бітне знакове ціле (int ∈ [-2,147,483,648; 2,147,483,647])

- Результат множення викликає переповнення (integer overflow)

- Залежно від реалізації:

  - num стає негативним числом або обнуляється

  - після передачі в malloc() (який очікує size_t — unsigned), від’ємне число стає 0

## Завдання 4.3: malloc(0)

**[Код](https://github.com/VladHume/pr4/blob/main/malloc_zero.c):**

**Аналіз:**
```bash
./malloc_zero
```
![image](https://github.com/user-attachments/assets/47a05f28-0dbb-4f73-9c29-3420c98845b7)

**Висновок:** malloc(0) може повернути:
- `NULL` або
- Унікальний вказівник, який **можна передати у free()**.

## Завдання 4.4: Помилка у циклі malloc/free

**Проблемний [код](https://github.com/VladHume/pr4/blob/main/malloc_wrong_loop.c):**

![image](https://github.com/user-attachments/assets/b23c2e4a-c879-468c-a062-71a4a1b05da8)

**Правильний [варіант](https://github.com/VladHume/pr4/blob/main/malloc_fixed_loop.c):**

![image](https://github.com/user-attachments/assets/f44c72f7-0ec3-42bf-98d4-d1d9ee72b60f)


## Завдання 4.5: realloc(3) не зміг виділити памʼять

**Тестовий приклад:**
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *ptr = malloc(16);
    if (!ptr) return 1;
    void *new_ptr = realloc(ptr, (size_t)-1); // дуже велике значення
    if (!new_ptr) {
        perror("realloc failed");
        free(ptr); // оригінальний ptr ще доступний
    } else {
        free(new_ptr);
    }
    return 0;
}
```

## Завдання 4.6: realloc(3) з NULL або розміром 0

```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    void *p1 = realloc(NULL, 100); // == malloc(100)
    void *p2 = realloc(p1, 0);     // == free(p1); return NULL
    printf("p1 = %p, p2 = %p\n", p1, p2);
    return 0;
}
```

**Висновок:**
- `realloc(NULL, size)` = `malloc(size)`
- `realloc(ptr, 0)` = `free(ptr); return NULL`

## Завдання 4.7: Використання reallocarray(3)

```c
#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>

struct sbar { int x; };

int main() {
    struct sbar *ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) return 1;
    struct sbar *newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        perror("reallocarray failed");
        free(ptr);
    } else {
        free(newptr);
    }
    return 0;
}
```

**Відмінність:** `reallocarray` безпечніший при переповненні розміру (захист від `size_t` overflow).

