

#ifndef game_h
#define game_h

#include "list.hpp"
#include "data.hpp"
#include "profiles.hpp"


#include <fstream>
#include <stdlib.h>
using std::stoi;

#include <time.h>

class Game
{
public:
//constructor
    Game(int input = 0);
//destructor
    ~Game();

//setters
    void setmenuval(int newnum)
    {
        this -> menuval = newnum;
    }
    void setpts(int newpoints)
    {
        this -> pts = newpoints;
    }

//getters
    int getmenuval(void)
    {
        return this -> menuval;
    }

//printing functions
    void printmenu();
    void printrules();
    void printlist(List<Data> &list);
    int size(List<Data> &commandslist);

//filling list functions
    void filllist(List<Data> &list, string file);
    void fillprofiles(Profile profiles[30], string file);
    void updatelist(List<Data> &list, string file);
    void updateprofiles(Profile profiles[30], string file);

//finding functions
    int findplayer(string player, Profile userlist[30]);
    Data dataindex(int index, List<Data> &commandslist);
    int checkcommands(List<Data> &commandslist, string command);

// add and remove
    void removecommand(List<Data> &commandslist);
    void addcommand(List<Data> &commandslist);
    void adduser(Profile userlist[30]);

//play game
    int playgame(List<Data> &commandslist);

private:
    int menuval;
    int pts;
  //  List<Data> commandslist;
  //  List<Data> userlist;
    std::fstream infile;
    std::fstream outfile;
};

#endif