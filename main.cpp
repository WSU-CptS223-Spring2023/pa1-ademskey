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

//std inclusions
#include <fstream>
#include <cstdlib>
#include <iostream>

//file inclusions
#include "data.hpp"
#include "node.hpp"
#include "list.hpp"
#include "game.hpp"

//using statements
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

//menu game + file variables
Game gamemenu;

int main(void)
{
    //print off the rules
    gamemenu.printmenu();

    while(gamemenu.getmenuval() != 7) //while 7 (exit number) hasnt been entered
    {
        //print menu
        // printmenu();
        switch(gamemenu.getmenuval())
        {
            case 1:
                //Print off Game Rules
                gamemenu.printrules();
            case 2:
                //Play new game
                gamemenu.filllist(gamemenu.getcommandslist()); //fills commands list
                //play game
                
            case 3:
                //load previous game
                gamemenu.filllist(gamemenu.getuserlist()); //fills user list
                //play game

            case 4:
                //add command 
            case 5:
                //remove command
            case 6:
                //print commands list
                gamemenu.printlist(gamemenu.getcommandslist());
            case 7:
                //save and exit
                return 0;
            
            default:
                cout << "Valid menu value not entered, try again" << endl;
        }
    }
    return 0; //return zero if main has executed succesfully
}
