
//list.h is the main header used

//gaurd code
#ifndef list_h
#define list_h

//include libraries
#include <iostream>
#include <string>

#include "Data.h"

//using statements
using std::string;

class List
{
public:
//constructor
    List();
//destructor
    ~List();
//insert
    void insert();
//delete
    Data depopulate();
//find node
    Data find(string command);


private:
    Node<Data>* pNext;

};

#endif