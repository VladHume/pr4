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

**Тестовий [приклад:](https://github.com/VladHume/pr4/blob/main/realloc_fail.c)**

![image](https://github.com/user-attachments/assets/d9afcd22-7b34-44e4-9549-38e2aef31cdc)


## Завдання 4.6: realloc(3) з NULL або розміром 0

[Код](https://github.com/VladHume/pr4/blob/main/realloc_zero.c)

![image](https://github.com/user-attachments/assets/1201591d-20d9-4b27-bc88-e69492e8ef3b)


## Завдання 4.7: Використання reallocarray(3)

[Код](https://github.com/VladHume/pr4/blob/main/reallocarray_test.c)

![image](https://github.com/user-attachments/assets/67fd5833-b4e5-46d8-909c-2771949d118e)

## Завдання по варіантах
[Код](https://github.com/VladHume/pr4/blob/main/individual.c)

![image](https://github.com/user-attachments/assets/47490519-b780-4230-b236-af8032c939db)


