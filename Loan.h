#ifndef LOAN_H
#define LOAN_H

#include <ctime>
#include <string>

using namespace std;
struct status_t
{
  char current;
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
  void SetPatronID(int i);
  int GetPatronID();
  void SetBookID(int i);
  int GetBookID();
  void SetDueDate(time_t t);
  time_t GetDueDate();
  void SetStatus(char stat, bool recheck);
  status_t GetStatus();
};

#endif