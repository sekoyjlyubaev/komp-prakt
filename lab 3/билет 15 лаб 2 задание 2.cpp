#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Point {
    double x, y, z;
};

struct Line {
    Point p1, p2;
};

struct Plane {
    double a, b, c, d;
};

// Функция для генерации случайного числа в заданном диапазоне
double randomInRange(double minVal, double maxVal) {
    return minVal + (double)rand() / RAND_MAX * (maxVal - minVal);
}

// Функция для генерации случайной точки в пространстве
Point generateRandomPoint() {
    Point p;
    p.x = randomInRange(-10, 10);
    p.y = randomInRange(-10, 10);
    p.z = randomInRange(-10, 10);
    return p;
}

// Функция для генерации случайной прямой в пространстве
Line generateRandomLine() {
    Line l;
    l.p1 = generateRandomPoint();
    l.p2 = generateRandomPoint();
    return l;
}

// Функция для генерации случайной плоскости в пространстве
Plane generateRandomPlane() {
    Plane p;
    p.a = randomInRange(-10, 10);
    p.b = randomInRange(-10, 10);
    p.c = randomInRange(-10, 10);
    p.d = randomInRange(-10, 10);
    return p;
}

// Функция для вычисления скалярного произведения векторов
double dotProduct(Point p1, Point p2) {
    return p1.x * p2.x + p1.y * p2.y + p1.z * p2.z;
}

// Функция для вычисления длины вектора
double vectorLength(Point p) {
    return sqrt(dotProduct(p, p));
}

// Функция для вычисления угла между прямой и плоскостью
double angleBetweenLineAndPlane(Line l, Plane p) {
    Point v = {l.p2.x - l.p1.x, l.p2.y - l.p1.y, l.p2.z - l.p1.z};
    Point n = {p.a, p.b, p.c};
    double cosAlpha = abs(dotProduct(v, n)) / (vectorLength(v) * vectorLength(n));
    return acos(cosAlpha) * 180 / M_PI;
}

// Функция для проверки параллельности прямой и плоскости
bool areLineAndPlaneParallel(Line l, Plane p) {
    Point v = {l.p2.x - l.p1.x, l.p2.y - l.p1.y, l.p2.z - l.p1.z};
    Point n = {p.a, p.b, p.c};
    return abs(dotProduct(v, n)) < 1e-6;
}

// Функция для вычисления расстояния между параллельными прямой и плоскостью
double distanceBetweenLineAndPlane(Line l, Plane p) {
    Point pointOnLine = l.p1;
    double numerator = abs(p.a * pointOnLine.x + p.b * pointOnLine.y + p.c * pointOnLine.z + p.d);
    double denominator = sqrt(p.a * p.a + p.b * p.b + p.c * p.c);
    return numerator / denominator;
}

// Функция для нахождения точки пересечения прямой и плоскости
Point intersectionPoint(Line l, Plane p) {
    Point v = {l.p2.x - l.p1.x, l.p2.y - l.p1.y, l.p2.z - l.p1.z};
    double t = -(p.a * l.p1.x + p.b * l.p1.y + p.c * l.p1.z + p.d) /
               (p.a * v.x + p.b * v.y + p.c * v.z);
    Point intersectionPoint;
    intersectionPoint.x = l.p1.x + t * v.x;
    intersectionPoint.y = l.p1.y + t * v.y;
    intersectionPoint.z = l.p1.z + t * v.z;
    return intersectionPoint;
}

int main() {
    srand(time(0));

    // Генерация случайной прямой и плоскости
    Line l = generateRandomLine();
    Plane p = generateRandomPlane();

    cout << "Прямая: (" << l.p1.x << ", " << l.p1.y << ", " << l.p1.z << ") - ("
         << l.p2.x << ", " << l.p2.y << ", " << l.p2.z << ")" << endl;
    cout << "Плоскость: " << p.a << "x + " << p.b << "y + " << p.c << "z + " << p.d << " = 0" << endl;

    // Вычисление угла между прямой и плоскостью
    double angle = angleBetweenLineAndPlane(l, p);
    cout << "Угол между прямой и плоскостью: " << angle << " градусов" << endl;

    // Проверка параллельности прямой и плоскости
    if (areLineAndPlaneParallel(l, p)) {
        // Вычисление расстояния между параллельными прямой и плоскостью
        double distance = distanceBetweenLineAndPlane(l, p);
        cout << "Прямая и плоскость параллельны. Расстояние между ними: " << distance << endl;
    } else {
        // Нахождение точки пересечения прямой и плоскости
        Point intersection = intersectionPoint(l, p);
        cout << "Прямая пересекает плоскость в точке: (" << intersection.x << ", "
             << intersection.y << ", " << intersection.z << ")" << endl;
    }

    return 0;
}
