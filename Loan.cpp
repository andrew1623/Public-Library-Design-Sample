#include <iostream>

#include "Loan.h"

using namespace std;

Loan::Loan(int i)
{
  // c = checked out
  // o = overdue
  // r = rechecked out
  status = 'c';
  loanID = i;

  // Create dueDate
  time_t t;
  struct tm *due;
  time(&t);
  due = localtime(&t);
  due->tm_mday += 10;
  dueDate = mktime(due);
}

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
void Loan::SetStatus(char s)
{
  this->status = s;
}
char Loan::GetStatus()
{
  return status;
}
void Loan::PrintDetails()
{
  string statStr;
  switch (status)
  {
  case 'c':
    statStr = "Checked Out";
    break;
  case 'o':
    statStr = "Overdue";
    break;
  case 'r':
    statStr = "Rechecked out";
    break;
  }

  cout << "\nLOAN DETAILS" << endl
       << "Loan ID: " << loanID << endl
       << "Patron ID: " << patronID << endl
       << "Book ID: " << bookID << endl
       << "Status: " << statStr << endl
       << "Due: " << ctime(&dueDate) << endl;
}