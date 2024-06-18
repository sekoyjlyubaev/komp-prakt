#include <iostream>
#include <cmath>

using namespace std;

int main() {
  double sum = 0.0;
  double term = 1.0;
  double eps = 1e-6; 
  int k = 1;

  while (abs(term) > eps) {
    term = 18.0 / pow(2, k - 1) + pow(-1, k - 1) / (2 * pow(3, k - 1));
    sum += term;
    k++;
  }

  cout << "Сумма ряда: " << sum << endl;
  cout << "Количество итераций: " << k - 1 << endl;

  return 0;
}
