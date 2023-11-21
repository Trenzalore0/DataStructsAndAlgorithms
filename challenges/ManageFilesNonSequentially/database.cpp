#include "database.h"

template <class T>
Database<T>::Database() {
}

template <class T>
void Database<T>::add(T& d) {
  database.open(fName, ios::in|ios::out|ios::binary);
  database.seekp(0, ios::end);
  d.writeToFile(database);
  database.close();
}

template <class T>
void Database<T>::modify(const T& d) {
  T tmp;
  database.open(fName, ios::in|ios::out|ios::binary);
  while (!database.eof()) {
    tmp.readFromFile(database);
    if (tmp == d) {
      cin >> tmp;
      database.seekp(-d.size(), ios::cur);
      tmp.writeToFile(database);
      database.close();
      return;
    }
  }
  database.close();
  cout << "The registry not exits!\n";
}

template <class T>
bool Database<T>::find(const T& d) {
  T tmp;
  database.open(fName, ios::in|ios::out|ios::binary);
  while (!database.eof()) {
    tmp.readFromFile(database);
    if (tmp == d) {
      database.close();
      return true;
    }
  }
  database.close();
  return false;
}

template <class T>
ostream& Database<T>::print(ostream& out) {
  T tmp;
  database.open(fName, ios::in|ios::out|ios::binary);
  while (true) {
    tmp.readFromFile(database);
    if (database.eof()) {
      break;
    }
    out << tmp << endl;
  }
  database.close();
  return out;
}

template <class T>
void Database<T>::run() {
  cout << "File name: ";
  cin >> fName;

  char option[5];
  T rec;
  
  cout << "1. Add 2. Find 3. Modify 4. save" << endl;
  cout << "choose one option: ";
  cin.getline(option, 4);
  while (cin.getline(option, 4)) {
    switch (*option) {
      case '1':
        cin >> rec;
        add(rec);
        break;
      case '2':
        rec.readKey();
        cout << "The Registry is ";
        if (find(rec) == false) {
          cout << "no " << endl;
        }
        cout << "exist " << endl;
        break;
      case '3':
        rec.readKey();
        modify(rec);
        break;
      default:
        cout << "Bad option " << endl;
    }
    cout << *this;
    cout << "choose one option: ";
    cin.getline(option, 4);
  }
}
