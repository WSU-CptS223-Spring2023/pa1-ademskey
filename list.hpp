
//list.h is the main header used

//gaurd code
#ifndef list_h
#define list_h

//include libraries
#include <iostream>
#include <string>

#include "node.hpp"

//using statements
using std::string;

template <typename nodetype>
class List
{
public:
//constructor
    List(Node<nodetype>* head)
    {
        this -> pHead = head;
    }
    List()
    {
        this -> pHead = nullptr;
    }
//destructor
    ~List()
    {
        //initialize and set a pCur as current head
        Node<nodetype>* pCur = pHead;
        Node<nodetype>* pTemp = nullptr;

        while(pCur -> getpnext() != nullptr)
        {
            pTemp = pCur; //set pCur to temp
            pCur = pCur -> getpnext(); //set pcur to the next
            delete pTemp;
        }

    }
//getter
    Node<nodetype>* getpHead()
    {
        return this -> pHead;
    }
  //setter  
    void setpHead(Node<nodetype>* newnode)
    {
        this -> pHead = newnode;
    }

//find node
    int find(string command);

//insert
    void insert(nodetype data)
    {
        //try not heap possible
        Node<nodetype>* newnode = new Node<nodetype>(data);

        if(newnode != nullptr)
        {
            if(this -> pHead == nullptr)
            {
                this -> pHead = newnode;
            }
            else
            {
                newnode -> setpNext(pHead); //pHead set to pNext
                this -> pHead = newnode; //update head

            }
        }
    }

private:
//pointer to next in data
    Node<nodetype>* pHead;
};

#endif