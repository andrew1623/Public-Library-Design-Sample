#include "Loans.h"
#include "Books.h"
#include "Patrons.h"

using namespace std;

void Loans::CheckInBook(int bkID)
{
}

void Loans::CheckOutBook(int bkID)
{
}
void SetLoanStatus(char stat, bool recheck);
void PrintOverdue();
void PrintLoansByPatron(string name);
void PrintLoansByPatron(int id);
void RecheckBook(int bkID);
void EditLoan(int lnID);
void ReportLost(int bkID);