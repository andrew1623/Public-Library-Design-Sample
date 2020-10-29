#include <iostream>
#include <string>
#include <cctype>
#include "patrons/Patrons.h"
#include "loans/Loans.h"
#include "books/Books.h"

using namespace std;

char getUserInput()
{
  char input;
  cout << "Enter a selection: " << endl;
  cin >> input;
  // idk about this loop
  // seems sus
  if (cin.fail() || !isalpha(input))
  {
    cout << "Selection must be a single character.\nEnter a selection: " << endl;
    cin >> input;
  }
  else
  {
    return input;
  }
}

void menu();

int main()
{
  Patrons patrons;
  Loans loans;
  Books books;

  return 0;
}