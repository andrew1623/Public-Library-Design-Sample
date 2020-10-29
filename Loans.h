#ifndef LOANS_H
#define LOANS_H

#include <vector>
#include "Books.h"
#include "Patrons.h"
#include "Loan.h"

class Loans
{
private:
  int count;
  vector<Loan> loansList;

public:
  Loans();
  void CheckInBook(Books bkList, Patrons pList);
  void CheckOutBook(Books bkList, Patrons pList);
  void SetLoanStatus(char stat, bool recheck);
  void PrintOverdue();
  void PrintLoansOfPatron(Patrons pList);
  void RecheckBook(Books bkList);
  void ReportLost(Books bkList, Patrons pList);
};

#endif