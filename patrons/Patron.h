#ifndef PATRON_H
#define PATRON_H

#include <string>

using namespace std;
class Patron
{
private:
  int id;
  string name;
  float balance;
  int booksOut;

public:
  Patron(int d, string n);
  void SetID(int i);
  int GetID();
  void SetName(string n);
  string GetName();
  void SetBalance(float b);
  float GetBalance();
  void SetBooksOut(int i);
  int GetBooksOut();
};
#endif