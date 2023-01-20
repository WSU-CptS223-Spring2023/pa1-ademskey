# This is an example makefile. A makefile is a file that contains
# a set of directives to automate the build of the software.
# This is a very basic form of a makefile! We will add more to our makefiles in the future!
prog: main.o Node.o game.o list.o Data.o
	g++ main.o message.o factorial.o -o ourProg

main.o: main.cpp Node.h game.cpp list.h Data.cpp
	g++ -c main.cpp

game.cpp.o: game.cpp game.h
	g++ -c game.cpp 

list.h.o: list.h
	g++ -c list.cpp

node.h.o: Node.h
	g++ -c node.cpp 

clean: 
	-rm *.o

run:
	@./pa1