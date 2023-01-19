# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o list.o node.o game.o
	g++ main.o message.o factorial.o -o ourProg

main.o: main.cpp
	g++ -c main.cpp

game.cpp.o: game.cpp game.h
	g++ -c game.cpp 

list.cpp.o: list.cpp list.h
	g++ -c list.cpp

node.cpp.o: node.cpp Node.h
	g++ -c node.cpp 

clean: 
	-rm *.o

run:
	@./pa1