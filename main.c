#include <stdio.h>
#include <stdint.h>
#include <windows.h>
#include "vector/vector.h"



void test_pushBack_fullVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    pushBack(&v, 20);
    printf("Размер вектора после добавления элемента: %zu\n", v.size);
    printf("Значение второго элемента: %d\n", v.data[1]);
}


void test() {

    test_pushBack_fullVector();
    // добавьте другие тесты здесь
}

int main() {
    SetConsoleOutputCP(65001); // Устанавливаем кодовую страницу UTF-8

    test(); // Вызываем тесты
    return 0;
}