#ifndef STUDENT
#define STUDENT

#include "personal.h"

class Student : public Personal {

  public:
    Student();
    Student(char*, char*, char*, int, long, char*);
    void writeToFile(fstream&) const;
    void readFromFile(fstream&);
    int size() const {
      return Personal::size() + majorLen;
    }
    
  protected:
    char *major;
    const int majorLen;
    ostream& writeLegibly(ostream&);
    friend ostream& operator<<(ostream& out, Student& st) {
      return st.writeLegibly(out);
    }
    istream& readFromConsole(istream&);
    friend istream& operator>>(istream& in, Student& st) {
      return st.readFromConsole(in);
    }
};

#endif
