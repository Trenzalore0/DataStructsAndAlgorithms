#include <iostream>

int i, j, *p, *q;

void show() {
  std::cout << std::endl;

  std::cout << "i: " << i << std::endl
       << "j: " << j << std::endl
       << "*p: " << *p << std::endl
       << "*q: " << *q << std::endl
       << "p: " << p << std::endl
       << "q: " << q << std::endl;

  std::cout << std::endl;
}

void execute() {
  // p = new int, q = new int; // alocação de memória dinamicamente

  // show();

  i = 15;

  p = &i;

  *p = 20;

  j = 2 * *p;

  q = &j;
  
  // show();

  *p = *q - 1;

  show();

  // p = new int;
  // p = 0;
  // delete p;
  // p = new int;
  // show();
}
