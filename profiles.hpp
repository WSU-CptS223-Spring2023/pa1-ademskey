
#ifndef profiles_h
#define profiles_h


#include <string>

using std::string;

class Profile
{
public:
//constructor
    Profile(string lastnamein = "No input", string nameinput = "No input", int pointsinput = 0)
    {
        this -> name = nameinput;
        this -> lastname = lastnamein;
        this -> points = pointsinput;
    }
//destructor
    ~Profile()
    {
        //inside destructor
    }
//getter
    string getname()
    {
        return this -> name;
    }
    int getpoints()
    {
        return this -> points;
    }
    string getlast()
    {
        return this -> lastname;
    }

//setters
    void setname(string newname)
    {
        this -> name = newname;
    }

    void setlast(string newlast)
    {
        this -> lastname = newlast;
    }

    void setpoints(int newpoints)
    {
        this -> points = newpoints;
    }
private:

    string name;
    string lastname;
    int points;
};

#endif