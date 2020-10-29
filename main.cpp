#include <iostream>
#include <string>
#include <cctype>
#include "Patrons.h"
#include "Loans.h"
#include "Books.h"

using namespace std;

char getUserInput()
{
  string input;
  cout << "Enter a selection: " << endl;
  cin >> input;

  //input validation
  if (!isalpha(input[0]) || input.size() > 1)
  {
    cout << "\nSelection must be a single character.\nEnter a selection: " << endl;
    cin >> input;
  }
  else
  {
    return input[0];
  }
}

void menu()
{
  char currChoice;
  while (currChoice != 'q')
  {
    cout << "\nMENU" << endl
         << "(o) Check out a Book" << endl
         << "(i) Check in a book" << endl
         << "(b) Add a book to the Library" << endl
         << "(p) Add a new patron" << endl
         << "(f) Pay fines" << endl
         << "(l) Report lost book" << endl
         << "(v) View collections"
         << "(q) Quit\n"
         << endl;
    currChoice = getUserInput();

    switch (currChoice)
    {
    case 'o':
      break;
    case 'i':
      break;
    case 'b':
      break;
    case 'p':
      break;
    case 'f':
      break;
    case 'l':
      break;
    case 'v':
      cout << "Select a collection to view." << endl;
    }
  }
}
void viewCollection()
{
}
int main()
{

  // Patrons patrons;
  // Loans loans;
  // Books books;
  // Need to load in books, loans, and patrons data file
  menu();

  return 0;
}