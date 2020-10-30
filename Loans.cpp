#include "Loans.h"
#include "Books.h"
#include "Patrons.h"
#include <iostream>

using namespace std;

Loans::Loans()
{
  count = 0;
}

void Loans::CheckOutBook(Books bkList, Patrons pList)
{
  string searchBName, searchPName, bookName, patronName;
  int bkID, pID;

  // Get names of book and patron
  cout << "\nCHECK BOOK IN " << endl
       << "Enter title of book: " << endl;
  cin.ignore();
  getline(cin, searchBName);
  cout << "Enter name of patron" << endl;
  getline(cin, searchPName);

  // find book and patron
  vector<Book>::iterator bk = bkList.FindBook(searchBName);
  vector<Patron>::iterator p = pList.FindPatron(searchPName);
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

void Loans::CheckInBook(Books bkList, Patrons pList)
{
  string findBName;
  int bkID, pID;
  // Get name of book to be returned
  cout << "Enter book title: " << endl;
  cin.ignore();
  getline(cin, findBName);
  // Find related book (pointer bkIt)
  vector<Book>::iterator bkIt = bkList.FindBook(findBName);
  vector<Loan>::iterator loanIt;
  while (loanIt != loansList.end())
  {
    // This will find the right loan (pointer loanIt)
    if (loanIt->GetBookID() == bkIt->GetId())
    {
      // Find related patron (pointer patIt)
      pID = loanIt->GetPatronID();
      vector<Patron>::iterator patIt = pList.FindPatron(pID);
      // check if overdue + update patron
      if (loanIt->GetStatus() == 'o')
      {
        float fee, tmp;
        tmp = patIt->GetBalance();
        // ***
        // TODO:calculate overdue fee

        // fee =
        // ***
        patIt->SetBooksOut(patIt->GetBooksOut() - 1);
      }
      else
      {
        patIt->SetBooksOut(patIt->GetBooksOut() - 1);
      }
      // update book status
      bkIt->SetStatus('i');
      // delete loan
      loansList.erase(loanIt);
    }
  }
}

void Loans::PrintOverdue()
{
  cout << "\nOVERDUE BOOKS" << endl;
  for (Loan loan : loansList)
  {
    if (loan.GetStatus == 'o')
    {
      loan.PrintDetails();
    }
  }
}

void Loans::PrintLoansOfPatron(Patrons pList)
{
  // Prompt for name
  string pName, foundName;
  int pID;
  cout << "Enter patron's name: " << endl;
  cin.ignore();
  getline(cin, pName);
  // Find patron's ID
  vector<Patron>::iterator p = pList.FindPatron(pName);
  pID = p->GetID();
  foundName = p->GetName();
  // Print loans with matching patronID
  cout << "\nPRINTING LOANS OF PATRON" << endl
       << "Patron: " << foundName << endl;
  for (Loan l : loansList)
  {
    if (l.GetPatronID() == pID)
    {
      l.PrintDetails();
    }
  }
}

void Loans::RecheckBook(Books bkList, Patrons pList)
{ // get name of book to be rechecked
  string bkName;
  cout << "Enter book title: " << endl;
  cin.ignore();
  getline(cin, bkName);
  // find matching book
  vector<Book>::iterator bkIt = bkList.FindBook(findBName);
  while (loanIt != loansList.end())
  {
    // This will find the right loan (pointer loanIt)
    if (loanIt->GetBookID() == bkIt->GetId())
    {
      // check loan status
      // if overdue calc fee
      if (loanIt->GetStatus() == 'o')
      {
        // Find related patron (pointer patIt)
        int pID = loanIt->GetPatronID();
        vector<Patron>::iterator patIt = pList.FindPatron(pID);
        time_t due, now;
        due = loanIt->GetDueDate();
        time(&now);
        double difference = difftime(now, due) / (60 * 60 * 24);
        float newBalance = static_cast<float> difference + patIt->GetBalance();
        patIt->SetBalance(newBalance);
      }
      // if rechecked already - print message
      else if (loanIt->GetStatus() == 'r')
      {
        cout << "You may only recheck out a book once." << endl
             << "Please return the book." << endl;
      }
      else
      {
      }
    }
  }
}

void Loans::ReportLost(Books bkList, Patrons pList)
{
  // get name of book to be reported lost
  string bkName;
  cout << "Enter book title: " << endl;
  cin.ignore();
  getline(cin, bkName);
  // find matching book
  vector<Book>::iterator bkIt = bkList.FindBook(findBName);
  while (loanIt != loansList.end())
  {
    // This will find the right loan (pointer loanIt)
    if (loanIt->GetBookID() == bkIt->GetId())
    {
      // Update book status
      bkIt->SetStatus('l');
      // Find related patron (pointer patIt)
      int pID = loanIt->GetPatronID();
      vector<Patron>::iterator patIt = pList.FindPatron(pID);
      // Find cost and add to patron balance
      float lostFee = bkIt->GetCost();
      lostFee += patIt->GetBalance();
      patIt->SetBalance(lostFee);
      // Remove loan from loansList
      loansList.erase(loanIt);
    }
  }
}