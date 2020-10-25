#ifndef LOAN_H
#define LOAN_H

#include <time.h>
#include <string>

using namespace std;
struct status_t
{
  char currentStatus;
  bool rechecked;
};
class Loan
{
private:
  int loanID;
  int bookID;
  int patronID;
  time_t dueDate;
  status_t status;

public:
  Loan(int lID, int bID, int pID, time_t due, status_t stat);

  void SetLoanID(int i);
  int GetLoanID();
  void SetBookID(int i);
  int GetBookID();
  void SetPatronID(int i);
  int GetBookID();
  void SetDueDate(time_t t);
  time_t GetDueDate();
  void SetStatus(char stat, bool recheck);
  status_t GetStatus();
  void PrintLoan();
};

#endif