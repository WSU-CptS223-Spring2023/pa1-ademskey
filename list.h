
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
    List(Node<Data>* pHead = nullptr);
//destructor
    ~List();
//insert
    void insert(Data newdata);
//delete
    Data depopulate();
//find node
    Data find(string command);

private:
//pointer to next in data
    Node<Data>* pHead;

};

#endif