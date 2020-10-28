#include <iostream>
#include <iomanip>
#include "Books.h"

void Books::AddBook()
{
  string auth, title, status;
  int isbn, id;
  float cost;

  // Get Book Details
  cout << "\nADD BOOK" << endl;
  cout << "Enter author: " << endl;
  cin.ignore();
  getline(cin, auth);
  cout << "Enter title: " << endl;
  getline(cin, title);
  cout << "Enter ISBN: " << endl;
  cin >> isbn;
  cout << "Enter cost: " << endl;
  cin >> cost;
  id = count + 1;
  count++;

  // Add new Book to bookList
  Book bookToAdd = Book(auth, title, isbn, id, cost);
  bookList.push_back(bookToAdd);
}

// NOTE: This function does not edit book.status
void Books::EditBook(vector<Book>::iterator it, char key)
{
  string ns, os;
  int ni, oi;
  float nf, of;
  switch (key)
  {
  // Edit Author
  case 'a':
    os = it->GetAuthor();
    cout << "Enter new Author: " << endl;
    cin.ignore();
    getline(cin, ns);
    it->SetAuthor(ns);
    cout << "Author changed from " << os << " to " << ns << endl;

  // Edit Title
  case 't':
    os = it->GetTitle();
    cout << "Enter new Title: " << endl;
    cin.ignore();
    getline(cin, ns);
    it->SetTitle(ns);
    cout << "Title changed from " << os << " to " << ns << endl;

  // Edit ISBN
  case 's':
    oi = it->GetISBN();
    cout << "Enter new ISBN: " << endl;
    cin >> ni;
    it->SetISBN(ni);
    cout << "ISBN changed from " << oi << " to " << ni << endl;

  // Edit ID
  case 'd':
    oi = it->GetId();
    cout << "Enter new ID: " << endl;
    cin >> ni;
    it->SetId(ni) ;
    cout << "ID changed from " << oi << " to " << ni << endl;

  // Edit Cost
  case 'c':
    of = it->GetCost();
    cout << "Enter new cost: " << endl;
    cin >> nf;
    it->SetCost(nf);
    cout << fixed << setprecision(2);
    cout << "Cost changed from $" << of << "to $" << nf << endl;
  }
}

void Books::DeleteBook(vector<Book>::iterator it)
{
  if (bookFound)
  {
    bookList.erase(it);
    cout << "Book deleted." << endl;
  }
}

vector<Book>::iterator Books::GetBookByID(int id)
{
  vector<Book>::iterator it = bookList.begin();
  while (it != bookList.end())
  {
    if (it->GetId() == id)
    {
      cout << "Found book." << endl;
      it->PrintBookDetails();
      bookFound = true;
      return it;
    }
    else
    {
      cout << "Book not found." << endl;
      bookFound = false;
    }
  }
}
vector<Book>::iterator Books::GetBookByName(string name)
{
  vector<Book>::iterator it = bookList.begin();
  while (it != bookList.end())
  {
    if (it->GetAuthor() == name)
    {
      cout << "Found book." << endl;
      it->PrintBookDetails();
      return it;
    }
    else
    {
      cout << "Book not found." << endl;
    }
  }
}

void Books::PrintBookList()
{
  cout << "\nPRINT ALL BOOKS" << endl;
  for (Book &book : bookList)
  {
    cout << "----------" << endl;
    book.PrintBookDetails();
  }
}
