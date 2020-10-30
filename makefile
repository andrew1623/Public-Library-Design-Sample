library: Loans.o Patrons.o Books.o main.o
	cc -o Library Loans.o Patrons.o Books.o main.o main.cpp
main.o: main.cpp Patrons.h Loans.h Books.h
	cc -c main.cpp
Loans.o: Loans.cpp Loan.h Books.h Book.h Patrons.h Patron.h
	cc -c Loans.cpp 
Patrons.o: Patrons.cpp Patron.h Books.h 
	cc -c Patrons.cpp 
Books.o: Books.cpp Book.h
	cc -c Books.cpp

clean:
	rm *.o