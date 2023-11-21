#ifndef DATABASE
#define DATABASE

#include "student.h"

template<class T>
class Database {
  
  public:
    Database();
    void run();

  private:
    fstream database;
    char fName[20];
    ostream& print(ostream&);
    void add(T& d);
    bool find(const T& d);
    void modify(const T& d);
    friend ostream& operator<<(ostream& out, Database& db) {
      return db.print(out);
    }
};

#endif
