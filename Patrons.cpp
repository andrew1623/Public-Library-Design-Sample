#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>

#include "Patrons.h"
#include "Books.h"

using namespace std;

Patrons::Patrons()
{
  count = 0;
}

int createID()
{
  int id;
  srand(time(NULL));
  id = (rand() % 1000 + 100000);
  return id;
}
void Patrons::AddPatron()
{
  string name;
  int i = createID();

  cout << "\nADD PATRON" << endl;
  cout << "Enter name: " << endl;
  cin.ignore();
  getline(cin, name);

  Patron p = Patron(i, name);
  count++;
  patronsList.push_back(p);
}
void Patrons::EditPatron(vector<Patron>::iterator it, char key)
{
  string ns, os;
  int ni, oi;
  float nf, of;
  switch (key)
  {
  // Edit name
  case 'n':
    os = it->GetName();
    cout << "Enter new name: " << endl;
    cin.ignore();
    getline(cin, ns);
    it->SetName(ns);
    cout << "Name changed from " << os << " to " << ns << endl;
  // Edit balance
  case 'b':
    of = it->GetBalance();
    cout << "Enter new balance: " << endl;
    cin >> nf;
    it->SetBalance(nf);
    cout << "Balance changed from " << of << " to " << nf << endl;

  // Edit booksOut
  case 'o':
    oi = it->GetBooksOut();
    cout << "Enter new # of books out: " << endl;
    cin >> ni;
    it->SetBooksOut(ni);
    cout << "# of books checked out is now: " << ni << endl;
  }
}
void Patrons::DeletePatron(vector<Patron>::iterator it)
{
  if (patronFound)
  {
    patronsList.erase(it);
  }
}
vector<Patron>::iterator Patrons::FindPatron(int pID)
{
  vector<Patron>::iterator it = patronsList.begin();
  while (it != patronsList.end())
  {
    if (it->GetID() == pID)
    {
      cout << "Found patron." << endl;
      patronFound = true;
      return it;
    }
    else
    {
      cout << "Patron not found." << endl;
      patronFound = false;
    }
  }
}
vector<Patron>::iterator Patrons::FindPatron(string name)
{
  vector<Patron>::iterator it = patronsList.begin();
  while (it != patronsList.end())
  {
    if (it->GetName() == name)
    {
      cout << "Found patron." << endl;
      it->PrintPatronDetails();
      patronFound = true;
      return it;
    }
    else
    {
      cout << "Patron not found." << endl;
      patronFound = false;
    }
  }
}
void Patrons::PrintPatronList()
{
  cout << "\nPRINT ALL PATRONS" << endl;
  for (Patron &patron : patronsList)
  {
    cout << "----------" << endl;
    patron.PrintPatronDetails();
  }
}
void Patrons::PrintPatron(vector<Patron>::iterator it)
{
  it->PrintPatronDetails();
}
void Patrons::PayFines(string name)
{
  vector<Patron>::iterator it = FindPatron(name);
  it->SetBalance(0);
  cout << "\nTHE LIBRARY HAS FORGIVEN" << endl
       << "The library forgives you.\nEmail me if you really want to pay fees." << endl
       << it->GetName() << "'s current balance is now " << it->GetBalance() << endl;
}