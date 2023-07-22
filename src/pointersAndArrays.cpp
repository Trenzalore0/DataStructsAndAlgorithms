#include <iostream>

void execute() {
  int a[5] = { 1, 2, 3, 4, 7 }, *p, sum, i, *q;

  // array notation
  // for (sum = a[0], i = 1; i < 5; i++) {
  //   sum += a[i];
  // }

  // std::cout << "sum: " << sum << std::endl;

  // pointer notation
  // for (sum = *a, i = 1; i < 5; i++) { // method 1
  //   sum += *(a + i);
  // }
  for (sum = *a, p = a + 1; p < a + 5; p++) { // method 2
    sum += *p;
  }
  std::cout << "sum: " << sum << std::endl;

  // pointers and usability testing
  // std::cout << "a: " << a << std::endl << "*a: " << *a << std::endl;
  // for (i = 1; i < 5; i++) {
  //   std::cout << "a + " << i << ": " << a + i << std::endl;
  //   std::cout << "* (a + " << i << "): " << *(a + i) << std::endl;
  // }

  int n = 10;
  p = new int[n];
  for (i = 0; i < n; i++) {
    *(p + i) = i + 1;
  }
  // for (sum = p[0], i = 1; i < n; i++) {
  //   sum += p[i];
  // }
  // std::cout << "sum: " << sum << std::endl;

  for (sum = *p, i = 1; i < n; i++) {
    sum += *(p + i);
  }
  std::cout << "sum: " << sum << std::endl;

  // for (sum = *p, q = p + 1; q < p + n; q++) {
  //   sum += *q;
  // }
  // std::cout << "sum: " << sum << std::endl;

  delete[] p; // delete array in pointer
}
