#include <iostream>
#include <string>
#include <cctype>
#include "Patrons.h"
#include "Loans.h"
#include "Books.h"

using namespace std;

// TODO:
// file storage system
// makefile
// success

char getUserInput()
{
  string input;
  cout << "Enter a selection: " << endl;
  cin >> input;

  //input validation
  while (!isalpha(input[0]) || input.size() > 1)
  {
    cout << "\nSelection must be a single character.\nEnter a selection: " << endl;
    cin >> input;
  }
  return input[0];
}

// payFines function. it used to take an amount to pay towards patron balance
// but the library would rather forgive
void libraryForgivenessProgram(Patrons p)
{
  string forgiven;
  cout << "Enter patron's name: " << endl;
  cin.ignore();
  getline(cin, forgiven);
  p.PayFines(forgiven);
}

void viewCollection(Patrons p, Loans l, Books b)
{
  char choice;
  cout << "\nVIEW COLLECTION" << endl
       << "Select a collection to view." << endl
       << "(p) View patrons" << endl
       << "(l) View overdue loans" << endl
       << "(b) View books" << endl;
  choice = getUserInput();
  switch (choice)
  {
  case 'p':
    p.PrintPatronList();
    break;
  case 'l':
    l.PrintOverdue();
    break;
  case 'b':
    b.PrintBookList();
    break;
  }
}

void menu(Patrons p, Loans l, Books b)
{
  char currChoice;
  while (currChoice != 'q')
  {
    cout << "\nMENU" << endl
         << "(o) Check out a Book" << endl
         << "(i) Check in a book" << endl
         << "(r) Recheck out a book" << endl
         << "(b) Add a book to the Library" << endl
         << "(p) Add a new patron" << endl
         << "(f) Pay fines" << endl
         << "(l) Report lost book" << endl
         << "(v) View collections" << endl
         << "(q) Quit\n"
         << endl;
    currChoice = getUserInput();
    switch (currChoice)
    {
    case 'o':
      l.CheckOutBook(b, p);
      break;
    case 'i':
      l.CheckOutBook(b, p);
      break;
    case 'b':
      b.AddBook();
      break;
    case 'p':
      p.AddPatron();
      break;
    case 'f':
      libraryForgivenessProgram(p);
      break;
    case 'l':
      l.ReportLost(b, p);
      break;
    case 'r':
      l.RecheckBook(b, p);
      break;
    case 'v':
      viewCollection(p, l, b);
      break;
    }
  }
}

int main()
{

  Patrons patrons;
  Loans loans;
  Books books;
  // Need to load in books, loans, and patrons data file
  menu(patrons, loans, books);

  return 0;
}