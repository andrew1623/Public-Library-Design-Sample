library: Loans.o Patrons.o Books.o main.cpp
	g++ -o Library Loans.o Patrons.o Books.o main.cpp
Loans.o: Loans.cpp Loan.h Books.h Patrons.h
	g++ -c Loans.cpp
Patrons.o: Patrons.cpp Patron.h Books.h
	g++ -c Patrons.cpp
Books.o: Books.cpp Book.h
	g++ -c Books.cpp