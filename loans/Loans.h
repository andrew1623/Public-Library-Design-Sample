#ifndef LOANS_H
#define LOANS_H

#include <vector>
#include "Loan.h"

class Loans
{
private:
  int count;
  vector<Loan> loansList;

public:
  Loans();
  void CheckInBook(int bkID);
  void CheckOutBook(int bkID);
  void SetLoanStatus(char stat, bool recheck);
  void PrintOverdue();
  void PrintLoansByPatron(string name);
  void PrintLoansByPatron(int id);
  void RecheckBook(int bkID);
  void EditLoan(int lnID);
  void ReportLost(int bkID);
};

#endif