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
#include <stdlib.h>

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
int switchvar;
string playername, lastname;
List<Data> commandslist;
List<Data> userlist;


int main(void)
{
    //fill command and user lists
    gamemenu.filllist(commandslist, "commands.csv"); //fills commands list
    gamemenu.filllist(userlist, "profiles.csv"); //fills user list

    while(gamemenu.getmenuval() != 7) //while 7 (exit number) hasnt been entered
    {
        //print menu
        //cout << "Press any button to continue" << endl;
        //std::cin.get();
        //system("clear");

        gamemenu.printmenu();
        std::cin >> switchvar;
        gamemenu.setmenuval(switchvar);

        switch(gamemenu.getmenuval())
        {
            case 1:
                //Print off Game Rules
                gamemenu.printrules();
               // cout << "Press any button to continue" << endl;
               // std::cin.get();
                break;

            case 2:
                //Play new game
                gamemenu.adduser(userlist);
                gamemenu.playgame(commandslist);
                break;
                
            case 3:
                //load previous game
                cout << "What is your name? "; //get user profile name
                std::cin >> playername;

                gamemenu.setpts(gamemenu.findplayer(playername, userlist)); //sets points after finding player
                gamemenu.playgame(commandslist); //play game

                break;
            case 4:
                //add command
                gamemenu.addcommand(commandslist);
                break;
            case 5:
                //remove command
                gamemenu.removecommand(commandslist);
                break;
            case 6:
                //print commands list
                gamemenu.printlist(commandslist);
                break;
            case 7:
                //update game and player lists
                gamemenu.updatelist(commandslist, "commands.csv");
                gamemenu.updatelist(userlist, "profiles.csv");
                cout << "Game is exiting" << endl;
                //game exits
                break;
            
            default:
                cout << "Valid menu value not entered, try again" << endl;
        }
    }
    return 0; //return zero if main has executed succesfully
}
