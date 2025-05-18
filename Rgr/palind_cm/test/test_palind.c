#include <stdio.h>
#include <assert.h>
#include "palind.h" 

void test_palind() {
    printf("Запуск тестов...\n");
    
    // Тест 1: Палиндром
    char *str1 = "abba";
    int result1 = palind(str1);
    printf("Тест 1: '%s' - результат %d\n", str1, result1);
    assert(result1 == 1);
    
    // Тест 2: Не палиндром
    char *str2 = "hello";
    int result2 = palind(str2);
    printf("Тест 2: '%s' - результат %d\n", str2, result2);
    assert(result2 == 0);
    
    printf("Все тесты пройдены успешно!\n");
}

int main() {
    test_palind();
    return 0;
}
