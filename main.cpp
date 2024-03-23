#include <iostream>
#include "integral.h"

int main() {
    integral tmp;
    printf("-----------------------\n");
    printf("integral: %lf\n", tmp.equation());
    printf("Оценка остатка: %lf\n", tmp.estim());
    printf("-----------------------\n");
    return 0;
}