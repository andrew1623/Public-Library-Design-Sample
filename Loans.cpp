#include "Loans.h"
#include "Books.h"
#include "Patrons.h"
#include <iostream>

using namespace std;

Loans::Loans()
{
  count = 0;
}
void Loans::CheckInBook(Books bkList, Patrons pList)
{
  string findBookName, findPatronName, bookName, patronName;
  int bkID, pID;

  // Get names of book and patron
  cout << "\nCHECK BOOK IN " << endl
       << "Enter title of book: " << endl;
  cin.ignore();
  getline(cin, findBookName);
  cout << "Enter name of patron" << endl;
  getline(cin, findPatronName);

  // find book and patron
  vector<Book>::iterator bk = bkList.FindBook(findBookName);
  vector<Patron>::iterator p = pList.FindPatron(findPatronName);
  bookName = bk->GetTitle();
  patronName = p->GetName();

  // check to see if patrons has 6 or more books
  int bksOut = p->GetBooksOut();
  if (bksOut >= 6)
  {
    cout << "Check out for \"" << bookName << "\" failed." << endl
         << patronName << " has too many books checked out." << endl;
    return;
  }

  // populate loan to add
  bkID = bk->GetId();
  pID = p->GetID();
  Loan loan(count + 1);
  loan.SetBookID(bkID);
  loan.SetPatronID(pID);

  // Print loan object
  cout << "\nLOAN CREATED" << endl;
  loan.PrintDetails();

  // update book status to 'o' (out)
  cout << "\nUPDATING BOOK STATUS" << endl;
  bk->SetStatus('o');

  // update patron object
  cout << "\nUPDATING PATRON LOANS" << endl;
  int incrementBkOut = p->GetBooksOut() + 1;
  p->SetBooksOut(incrementBkOut);

  // add loan to vector and update count
  cout << "\nADDING LOAN TO MEMORY" << endl;
  count++;
  loansList.push_back(loan);
}

void Loans::CheckOutBook(Books bkList, Patrons pList)
{
}
void Loans::SetLoanStatus(char stat, bool recheck)
{
}
void Loans::PrintOverdue()
{
}
void Loans::PrintLoansOfPatron(Patrons pList)
{
}
void Loans::RecheckBook(Books bkList)
{
}
void Loans::ReportLost(Books bkList, Patrons pList)
{
}