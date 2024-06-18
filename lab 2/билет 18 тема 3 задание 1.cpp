#include <iostream>
#include <cmath>

// Функция, подлежащая интегрированию
double f(double x) {
    return x * x * x * x / (18 + x * x);
}

// Функция для вычисления определённого интеграла методом Симпсона
double simpsonsRule(double (*func)(double), double a, double b, int n) {
    if (n % 2 == 1) {
        n++;  // Метод Симпсона требует четного количества промежутков
    }
    double h = (b - a) / n;
    double result = func(a) + func(b);

    for (int i = 1; i < n; i += 2) {
        result += 4 * func(a + i * h);
    }
    for (int i = 2; i < n - 1; i += 2) {
        result += 2 * func(a + i * h);
    }
    
    result *= h / 3;
    return result;
}