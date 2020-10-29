#ifndef LOAN_H
#define LOAN_H

#include <ctime>
#include <string>

using namespace std;
class Loan
{
private:
  int loanID;
  int bookID;
  int patronID;
  time_t dueDate;
  char status;

public:
  Loan(int i);
  void SetLoanID(int i);
  int GetLoanID();
  void SetPatronID(int i);
  int GetPatronID();
  void SetBookID(int i);
  int GetBookID();
  void SetDueDate(time_t t);
  time_t GetDueDate();
  void SetStatus(char s);
  char GetStatus();
  void PrintDetails();
};

#endif