#include <iostream>

int n = 5;
int* p = &n; // pointer
int& r = n; // reference variable
// int const* r = &n; // another form to create reference variables

void show() {
  std::cout << std::endl;

  std::cout << " n: " << n 
            << "\n p: " << p 
            << "\n*p: " << *p 
            << "\n&p: " << &p 
            << "\n r: " << r 
            << "\n&r: " << &r
            << "\n&n: " << &n << std::endl << std::endl;
}

void f1(int i, int* j, int& k) {
  i = 1;
  *j = 2;
  k = 3;
}

int& f2(int a[], int i) {
  return a[i];
}

int* f3(int a[], int i) {
  return &a[i];
}

class C {
  public:
    int& getRefN() {
      return n;
    }
    int getN() {
      return n;
    }
  private:
  int n;
} C1;

void execute() {

  show();

  n = 7;
  *p = 9;
  r = 10;

  show();

  int n1 = 4, n2 = 5, n3 = 6;
  f1(n1, &n2, n3);
  std::cout << "n1: " << n1 << " n2: " << n2 << " n3: " << n3 << std::endl;

  int a[] = { 1, 2, 3, 4, 5 };
  f2(a, 3) = 6;
  n = f2(a, 3);
  show();

  *f3(a, 2) = 8;
  n = *f3(a, 2);
  show();

  int& ref = C1.getRefN();
  ref = 42;
  std::cout << C1.getN() << std::endl;
}
