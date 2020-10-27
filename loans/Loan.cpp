#include <iostream>
#include "Loan.h"

using namespace std;

void Loan::SetLoanID(int i)
{
  this->loanID = i;
}
int Loan::GetLoanID()
{
  return loanID;
}
void Loan::SetBookID(int i)
{
  this->bookID = i;
}
int Loan::GetBookID()
{
  return bookID;
}
void Loan::SetPatronID(int i)
{
  this->patronID = i;
}
int Loan::GetPatronID()
{
  return patronID;
}
void Loan::SetDueDate(time_t t)
{
  this->dueDate = t;
}

time_t Loan::GetDueDate()
{
  return dueDate;
}
void Loan::SetStatus(char stat, bool recheck)
{
  status_t s;
  status.current = stat;
  status.rechecked = recheck;
  this->status = s;
}
status_t Loan::GetStatus()
{
  return status;
}
void Loan::PrintLoan()
{
  char curStatus = status.current;
  string rechecked;

  if (status.rechecked)
  {
    rechecked = "True";
  }
  else
  {
    rechecked = "False";
  }

  cout << "\nLoan ID: " << loanID << endl
       << "Patron ID: " << patronID << endl
       << "Book ID: " << bookID << endl
       << "Due: " << dueDate << endl
       << "Status: " << status.current << endl
       << "Has been recheckin in: " << rechecked << endl;
}