#include <iostream>
#include <iomanip>
#include "Patron.h"

using namespace std;

Patron::Patron(int d, string n)
{
  id = d;
  name = n;
  balance = 0;
  booksOut = 0;
}

void Patron::SetID(int i)
{
  this->id = i;
}
int Patron::GetID()
{
  return id;
}
void Patron::SetName(string n)
{
  this->name = n;
}
string Patron::GetName()
{
  return name;
}
void Patron::SetBalance(float b)
{
  this->balance = b;
}
float Patron::GetBalance()
{
  return balance;
}
void Patron::SetBooksOut(int i)
{
  this->booksOut = i;
}
int Patron::GetBooksOut()
{
  return booksOut;
}

void Patron::PrintPatronDetails()
{
  cout << fixed << setprecision(2);
  cout << "ID: " << id << endl
       << "Name: " << name << endl
       << "Balance: $" << balance << endl
       << "# of Books out: " << booksOut << endl;
}