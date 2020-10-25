#include <iostream>
#include "Books.h"
using namespace std;
int main()
{
  char ignoreChar;
  cout << "Enter a char to be ignored" << endl;
  cin >> ignoreChar;

  Books bookList;
  bookList.AddBook();
  bookList.AddBook();
  bookList.PrintBookList();
  bookList.DeleteBook(1);
  bookList.PrintBookList();

  return 0;
}