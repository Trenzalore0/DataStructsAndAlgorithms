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
            << "\n&n: " << &n << std::endl;
}

void execute() {

  show();

  n = 7;
  *p = 9;
  r = 10;
  
  show();
}
