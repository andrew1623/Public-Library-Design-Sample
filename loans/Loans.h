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
  void CheckInBook(vector<Book>::iterator bit, vector<Patron>::iterator pit);
  void CheckOutBook(vector<Book>::iterator bit, vector<Patron>::iterator pit);
  void SetLoanStatus(char stat, bool recheck);
  void PrintOverdue();
  void PrintLoansOfPatron(vector<Patron>::iterator it);
  void RecheckBook(vector<Book>::iterator it);
  void EditLoan(vector<Book>::iterator it);
  void ReportLost(vector<Book>::iterator it);
};

#endif