#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book
{
private:
  string author;
  string title;
  int isbn;
  int id;
  float cost;
  char status;

public:
  // Constructor -- status defaults to "In"
  Book(string a, string t, int is, int d, float cost);

  // Set/Get functions
  void SetAuthor(string name);
  string GetAuthor();
  void SetTitle(string title);
  string GetTitle();
  void SetISBN(int isbn);
  int GetISBN();
  void SetId(int id);
  int GetId();
  void SetCost(float cost);
  float GetCost();
  void SetStatus(char status);
  char GetStatus();

  // Helper-Print functions
  string statusToString(char status);
  void PrintBookDetails();
};

#endif
