
#include "list.h"
#include "Node.h"

//destructor
List:: ~List()
{
    Node<Data>* pTemp;

    while(pHead != nullptr)
    {

    pTemp = this -> pHead; //set temp to head
    this -> pHead = pHead -> getpNext(); //incrament head
    delete pTemp; //deletes pTemp and it's data
    
    }
}
//insert
void List::insert(Data newdata)
{
    Node<Data>* newdata = new Node(newdata);
}
//delete
Data List::depopulate()
{

}
//find node
Data List::find(string command)
{

}