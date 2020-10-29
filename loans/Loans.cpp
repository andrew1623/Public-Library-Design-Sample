#include "Loans.h"
#include "Books.h"
#include "Patrons.h"

using namespace std;

Loans::Loans()
{
  count = 0;
}
void Loans::CheckInBook(Books bkList, Patrons pList)
{
}
void Loans::CheckOutBook(Books bkList, Patrons pList)
{
}
void Loans::SetLoanStatus(char stat, bool recheck)
{
}
void Loans::PrintOverdue()
{
}
void Loans::PrintLoansOfPatron(Patrons pList)
{
}
void Loans::RecheckBook(Books bkList)
{
}
void Loans::EditLoan(vector<Loan>::iterator it)
{
}
void Loans::ReportLost(vector<Loan>::iterator it)
{
}