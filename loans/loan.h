#ifndef LOAN_H
#define LOAN_H

#include <time.h>
#include <string>

using namespace std;

class Loan
{
private:
  int loanID;
  int bookID;
  int patronID;
  time_t DueDate;
  string status;
  bool rechecked;

public:
  void SetLoanID(int i);
  int GetLoanID();

  void SetBookID(int i);
  int GetBookID();

  void SetPatronID(int i);
  int GetBookID();

  void SetDueDate(time_t time);
  int GetDueDate();
};

#endif