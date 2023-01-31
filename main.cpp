// 

//Name: Linux Commands Quiz Game (PA 1)
// Author: Adam Caudle
// Date Created: 1/13/2023
// Preconditions: None (know how to work a terminal maybey)
// Postconditions: None
// Date Last Edited 1/13/2023

// **** Linked List Advantages / Disadvantages ++ Array Advantages / disadvantages**** 

// The advantages of linked lists is that they are dynamic and very versitile. When you are
// unsure of how much data you need to store linked list impleentation is incredibly useful to avoid
// the limitations / memory problems of other containers. because there is not a lmited ammount of commands which 
// using an array which is not desireable thus a list was used.

// The disadvantages of linked lists is that they are not always the most efficient for data storage and can 
// run into time complexity problems when searching through them for specific data. This means while they
// are versitile that they should only be used in the correct circumstances to avoid inneficient code. i
//since there is likely to not be a large ammount of profiles it was more efficent to use an array.


//The advantages of Arrays are instand (constant time) indexing and more efficency for smaller data groups
//for instance since there is likely to not be a large ammount of profiles it was more efficent to use an array.

//The disadvantages of arrays is that their size is set so you can run into memory issues easily as well as being rigid
//making them useful in specific senarios. for example this assignment would have a limited ammount of commands which 
//if using an array which is not desireable thus a list was used.

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
#include "profiles.hpp"

//using statements
using std::cout;
using std::endl;
using std::ifstream;
using std::ofstream;

//menu game + file variables
Game gamemenu;
int switchvar, playerindex, playerpoints;
string playername, lastname;
List<Data> commandslist;
Profile userlist[30];


int main(void)
{
    //fill command and user lists
    gamemenu.filllist(commandslist, "commands.csv"); //fills commands list
    gamemenu.fillprofiles(userlist, "profiles.csv");

    while(gamemenu.getmenuval() != 7) //while 7 (exit number) hasnt been entered
    {

        gamemenu.printmenu();
        std::cin >> switchvar;
        gamemenu.setmenuval(switchvar);

        switch(gamemenu.getmenuval())
        {
            case 1: //working
                //Print off Game Rules
                gamemenu.printrules();
                break;

            case 2:
                //Play new game
                gamemenu.adduser(userlist);
                playerpoints = gamemenu.playgame(commandslist);
                break;
                
            case 3:
                //load previous game
                cout << "What is your name? "; //get user profile name
                std::cin >> playername;

                playerindex = gamemenu.findplayer(playername, userlist); //find index of player
                gamemenu.setpts(userlist[playerindex].getpoints()); //sets points after finding player
                
                playerpoints = gamemenu.playgame(commandslist); //play game and return points
                userlist[playerindex].setpoints(playerpoints); //set points
                break;
            case 4:
                //add command
                gamemenu.addcommand(commandslist);
                break;

            case 5:
                //remove command
                gamemenu.removecommand(commandslist);
                break;

            case 6: //working
                //print commands list
                gamemenu.printlist(commandslist);
                break;

            case 7:
                //update game and player lists
                gamemenu.updatelist(commandslist, "commands.csv");
                gamemenu.updateprofiles(userlist, "profiles.csv");
                cout << "Game is exiting" << endl;
                //game exits
                break;
            
            default: //working
                cout << "Valid menu value not entered, try again" << endl;
                break;
        }
    }
    return 0; //return zero if main has executed succesfully
}
