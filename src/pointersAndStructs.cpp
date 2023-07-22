#include <iostream>
#include <string.h>

struct Node {
    char* name;
    int age;
    Node(char* n = "", int a = 0) {
      name = strdup(n);
      age = a;
    }
    Node(const Node& n) { // without this function copy another struct the compiler create than, but pointers look
      // the same memory location
      name = strdup(n.name);
      age = n.age;
    }
    // Node& operator=(const Node& n) { // the same thing happens with operator iqual
    //   if (this != &n) {
    //     if (name != 0) {
    //       free((void*)name);
    //     }
    //     name = strdup(n.name);
    //     age = n.age;
    //   }
    //   return *this;
    // }
    ~Node() { // Detructor
      if (name != 0)
        free(name);
    }
};

void execute() {
  Node node1("Roger", 20);
  Node node2(node1);
  // Node node2 = node1;

  strcpy(node2.name, "Wendy");
  node2.age = 30;

  std::cout << node1.name << ' ' << node1.age << std::endl;
  std::cout << node2.name << ' ' << node2.age << std::endl;
}
