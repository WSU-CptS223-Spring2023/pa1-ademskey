// 

//Name: Linux Commands Quiz Game (PA 1)
// Author: Adam Caudle
// Date Created: 1/13/2023
// Preconditions: None (know how to work a terminal maybey)
// Postconditions: None
// Date Last Edited 1/13/2023

// **** Linked List Advantages / Disadvantages **** 
// The advantages of linked lists is that they are dynamic and very versitile. When you are
// unsure of how much data you need to store linked list impleentation is incredibly useful to avoid
// the limitations / memory problems of other containers. 

// The disadvantages of linked lists is that they are not always the most efficient for data storage and can 
// run into time complexity problems when searching through them for specific data. This means while they
// are versitile that they should only be used in the correct circumstances to avoid inneficient code.

#include "data.hpp"
#include "node.hpp"
#include "list.hpp"
#include "game.hpp"


using std::cout;
using std::endl;

//Game gamemenu;

int main(void)
{
    int menuval = 7;

    while(menuval != 7) //while 7 (exit number) hasnt been entered
    {
        //print menu
        // printmenu();
        switch(menuval)
        {
            case 1:
                //Game Rules
                // printrules();
            case 2:
                //Play new game
            case 3:
                //load previous game
            case 4:
                //add command 
            case 5:
                //remove command
            case 6:
                //Display all commands
            case 7:
                //save and exit
                return 0;
            
            default:
                cout << "Valid menu value not entered, try again" << endl;
        }
    }
    return 0; //return zero if main has executed succesfully
}
