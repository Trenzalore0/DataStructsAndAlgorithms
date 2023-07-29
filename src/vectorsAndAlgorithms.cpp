#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <string.h>

template<class T> void print_vector(const std::vector<T>& v) {
  if (v.size() == 0) {
    std::cout << " has nothing " << std::endl;
    return;
  }
  typename std::vector<T>::const_iterator i = v.begin();
  for (; i < v.end(); i++) {
    std::cout << *i << std::endl;
  }
  std::cout << std::endl << std::endl;
}

bool f1(int n) {
  return n % 2 == 0;
}

class Person {
  public:
    Person(char* n = "", int a = 0) {
      age = a;
      name = strdup(n);
    }

    ~Person() {
      free(name);
    }

    bool operator==(const Person& p) const {
      return strcmp(name, p.name) == 0 && age == p.age;
    }

    bool operator<(const Person& p) const {
      return strcmp(name, p.name) < 0;
    }

    bool operator>(const Person& p) const {
      return !(*this == p) && !(*this < p);
    }

    char* getName() {
      return name;
    }

    int getAge() {
      return age;
    }

  private:
    char* name;
    int age;
    friend bool lowerAge(const Person&, const Person&);
};

void execute() {
  std::vector<int> v1 = std::vector<int>();

  v1.push_back(1);
  print_vector(v1);

  v1.insert(v1.begin(), 1, 3);
  print_vector(v1);

  v1.insert(v1.end(), 3, 5);
  print_vector(v1);

  v1.erase(v1.end() - 2);
  print_vector(v1);

  // v1.assign(3, 2);
  print_vector(v1);

  // algorithms

  std::replace_if(v1.begin(), v1.end(), f1, 3);
  print_vector(v1);

  std::replace(v1.begin(), v1.end(), 0, 7);
  print_vector(v1);

  std::sort(v1.begin(), v1.end());
  print_vector(v1);

  std::sort(v1.begin(), v1.end(), std::greater<int>());
  print_vector(v1);

  // v1.front() = 2;

  std::vector<Person> v2(0, Person("Gregg", 25));
  v2.push_back(Person("Ann", 30));
  // v2.push_back(Person("Bill", 20));

  std::cout << "test" << std::endl;

  std::sort(v2.begin(), v2.end());
  for (Person& person : v2) {
    std::cout << person.getAge() << " " << (char*)person.getName() << std::endl;
  }

  // std::sort(v2.begin(), v2.end(), std::greater<Person>());
  // print_vector(v2);
}
