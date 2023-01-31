
#ifndef data_h
#define data_h

#include <iostream>
#include "list.hpp"

using std::string;

class Data
{
public:
//constructor
    Data(string ans1 = "No input", string ans2 = "No input", int ans3 = 0)
    {
        this -> command = ans1;
        this -> answer = ans2;
        this -> points = ans3;
    }
//copy constructor
    Data data(Data data)
    {
        this -> command = data.getcommand();
        this -> answer = data.getanswer();
        this -> points = data.getpoints();
        return *this;
    }
//destructor
    ~Data()
    {
        //inside data destructor
    }
//setters
    void setcommand(string input)
    {this -> command = input;}

    void setanswer(string input)
    {this -> answer = input; }

    void setpoints(int input)
    {this -> points = input; }
//getters
    string getcommand()
    {return command;}

    string getanswer()
    {return answer;}

    int getpoints()
    {return points;}

private:
    //private member variables to store the command, answer, and points it is worth
    string command;
    string answer;
    int points;
};

std::ostream& operator << (std::ostream& lhs, Data rhs);

std::ofstream& operator << (std::ofstream& lhs, Data rhs);

#endif