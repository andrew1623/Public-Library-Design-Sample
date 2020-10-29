#ifndef BOOKS_H
#define BOOKS_H

#include <string>
#include <vector>
#include "Book.h"

using namespace std;

class Books
{
private:
  int count = 0;
  vector<Book> bookList;
  bool bookFound = false;

public:
  Books();
  // Edit bookList functions
  void AddBook();
  void EditBook(vector<Book>::iterator, char key);
  void DeleteBook(vector<Book>::iterator it);

  // Search/Find Book in booksList
  // - returns an iterator
  vector<Book>::iterator GetBookByID(int id);
  vector<Book>::iterator GetBookByName(string name);

  // Print booksList / Book details
  void PrintBookList();
};

#endif