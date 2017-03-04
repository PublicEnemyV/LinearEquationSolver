all: main.o LinearEquation.o
	g++ main.o LinearEquation.o -o test.exe

main.o: main.cpp
	g++ -c main.cpp

LinearEquation.o: LinearEquation.cpp
	g++ -c LinearEquation.cpp

clean:
	del main.o LinearEquation.o test.exe
