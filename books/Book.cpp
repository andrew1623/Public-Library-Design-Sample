#include <iostream>
#include <iomanip>
#include "Book.h"

using namespace std;

Book::Book(string a, string t, int is, int d, float c)
{
  author = a;
  title = t;
  isbn = is;
  cost = c;
  id = d;
  status = "In";
}

void Book::SetAuthor(string name)
{
  this->author = name;
}
string Book::GetAuthor()
{
  return author;
}
void Book::SetTitle(string title)
{
  this->title = title;
}
string Book::GetTitle()
{
  return title;
}
void Book::SetISBN(int isbn)
{
  this->isbn = isbn;
}
int Book::GetISBN()
{
  return isbn;
}
void Book::SetId(int id)
{
  this->id = id;
}
int Book::GetId()
{
  return id;
}
void Book::SetCost(float cost)
{
  this->cost = cost;
}
float Book::GetCost()
{
  return cost;
}
void Book::SetStatus(string status)
{
  this->status = status;
}
string Book::GetStatus()
{
  return status;
}

void Book::PrintBookDetails()
{
  cout << fixed << setprecision(2);
  cout << "Title: " << title << endl
       << "Author: " << author << endl
       << "ISBN: " << isbn << endl
       << "ID: " << id << endl
       << "Cost: $" << cost << endl;
}