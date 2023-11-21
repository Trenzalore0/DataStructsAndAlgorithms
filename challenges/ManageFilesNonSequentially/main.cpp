#include "personal.cpp"
#include "student.cpp"
#include "database.cpp"

void execute() {
  Database<Personal>().run();
  // Database<Student>().run();
}