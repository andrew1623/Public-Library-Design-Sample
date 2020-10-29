library: Loans.o Patrons.o Books.o main.cpp
	g++ -o library Loans.o Patrons.o Books.o main.cpp
loans.o: Loans.cpp Loan.h Books.h Patrons.h
	g++ -c loans.cpp
patrons.o: Patrons.cpp Patron.h Books.h
	g++ -c patrons.cpp
books.o: Books.cpp Book.h
	g++ -c books.cpp