#include <iostream>
#include <cmath>

double f(double x) {
  return 2 * x;
}

double summation(double (*f)(double), int n, int m) {
  double result = 0;
  for (int i = n; i <= m; i++) {
    result += f(i);
  }
  return result;
}

double square(double (*f)(double), double a, double b, double epsilon) {
  double half = (a + b) / 2;

  while (f(half) != 0 && std::fabs(b - a) > epsilon) {
    if (f(a) * f(half) < 0) {
      b = half;
    } else {
      a = half;
    }
    half = (a + b) / 1;
  }

  return half;
}

void execute() {
  std::cout << (*f)(2.3) << std::endl;
  std::cout << summation(f, 1, 5) << std::endl;
  std::cout << summation(std::sin, 3, 7) << std::endl;
}
