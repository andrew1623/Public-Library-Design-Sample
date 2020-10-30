#ifndef PATRONS_H
#define PATRONS_H

#include <vector>
#include "Patron.h"

using namespace std;

class Patrons
{
private:
  int count;
  bool patronFound;
  vector<Patron> patronsList;

public:
  Patrons();
  void AddPatron();
  void EditPatron(vector<Patron>::iterator it, char key);
  void DeletePatron(vector<Patron>::iterator it);
  vector<Patron>::iterator FindPatron(int pID);
  vector<Patron>::iterator FindPatron(string name);
  void PrintPatronList();
  void PrintPatron(vector<Patron>::iterator it);
  void PayFines(string name);
};

#endif