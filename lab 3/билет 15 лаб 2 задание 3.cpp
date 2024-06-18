#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y;
};

struct Ellipse {
    Point center;
    double a, b; // Полуоси
};

// Функция для генерации случайного числа в заданном диапазоне
double randomInRange(double minVal, double maxVal) {
    return minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
}

// Функция для генерации случайной точки
Point generateRandomPoint() {
    Point p;
    p.x = randomInRange(-10, 10);
    p.y = randomInRange(-10, 10);
    return p;
}

// Функция для генерации случайного эллипса
Ellipse generateRandomEllipse() {
    Ellipse e;
    e.center = generateRandomPoint();
    e.a = randomInRange(1, 5); // Полуось a > 0
    e.b = randomInRange(1, 5); // Полуось b > 0
    // Обеспечиваем, чтобы a было больше или равно b
    if (e.a < e.b) {
        swap(e.a, e.b);
    }
    return e;
}

// Функция для проверки принадлежности точки эллипсу
bool isPointInsideEllipse(Point p, Ellipse e) {
    double dx = p.x - e.center.x;
    double dy = p.y - e.center.y;
    return (dx * dx) / (e.a * e.a) + (dy * dy) / (e.b * e.b) <= 1;
}

// Функция для нахождения координат фокусов эллипса
Point* findEllipseFoci(Ellipse e) {
    Point* foci = new Point[2];
    double c = sqrt(e.a * e.a - e.b * e.b);
    foci[0].x = e.center.x - c;
    foci[0].y = e.center.y;
    foci[1].x = e.center.x + c;
    foci[1].y = e.center.y;
    return foci;
}

// Функция для нахождения эксцентриситета эллипса
double findEllipseEccentricity(Ellipse e) {
    return sqrt(1 - (e.b * e.b) / (e.a * e.a));
}

// Функция для нахождения расстояния от директрис эллипса до его центра
double findDistanceToDirectrix(Ellipse e) {
    return e.a / findEllipseEccentricity(e);
}

int main() {
    srand(time(0));

    // Генерация случайного эллипса и точки
    Ellipse e = generateRandomEllipse();
    Point p = generateRandomPoint();

    cout << "Эллипс: центр (" << e.center.x << ", " << e.center.y << "), a = "
         << e.a << ", b = " << e.b << endl;
    cout << "Точка: (" << p.x << ", " << p.y << ")" << endl;

    // Проверка принадлежности точки эллипсу
    if (isPointInsideEllipse(p, e)) {
        cout << "Точка принадлежит эллипсу" << endl;
    } else {
        cout << "Точка не принадлежит эллипсу" << endl;
    }

    // Нахождение координат фокусов
    Point* foci = findEllipseFoci(e);
    cout << "Координаты фокусов: (" << foci[0].x << ", " << foci[0].y << "), ("
         << foci[1].x << ", " << foci[1].y << ")" << endl;
    delete[] foci;

    // Нахождение длины полуосей
    cout << "Длина полуоси a: " << e.a << endl;
    cout << "Длина полуоси b: " << e.b << endl;

    // Нахождение эксцентриситета
    double eccentricity = findEllipseEccentricity(e);
    cout << "Эксцентриситет эллипса: " << eccentricity << endl;

    // Нахождение расстояния от директрис до центра
    double distanceToDirectrix = findDistanceToDirectrix(e);
    cout << "Расстояние от директрис до центра: " << distanceToDirectrix << endl;

    return 0;
}
