#ifndef PATRONS_H
#define PATRONS_H

#include <vector>
#include "Patron.h"

using namespace std;

class Patrons
{
private:
  int count;
  vector<Patron> patronsList;

public:
  Patrons();
  void AddPatron(Patron p);
  void EditPatron(int pID);
  void DeletePatron(int pID);
  vector<Patron>::iterator FindPatron(int pID);
  vector<Patron>::iterator FindPatron(string name);
  void PrintPatronList();
  void PrintPatron(int pID);
  void PayFines(int pID);
};

#endif;