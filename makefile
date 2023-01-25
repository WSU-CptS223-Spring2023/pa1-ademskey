# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!

prog: main.o game.o  data.o
	g++ -g main.o game.o data.o -o ourProg

main.o: main.cpp node.hpp game.cpp list.hpp data.cpp
	g++ -g -c main.cpp

game.o: game.cpp game.hpp list.hpp data.hpp
	g++ -g -c game.cpp 

data.o: data.cpp data.hpp list.hpp
	g++ -g -c data.cpp

clean: 
	-rm *.o

run:
	@./pa1