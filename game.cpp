
#include "game.hpp"

using std::cout;
using std::endl;
using std::cin;

Game::Game(int input)
{ 
    this -> menuval = input;
}

Game::~Game()
{
    //inside destructor
}

void Game::printmenu()
{
    system("cls");
    system("pause");
    cout << "**** Welcome to the Linux Command Quiz!" << endl;
    cout << "1. Print Rules" << endl;
    cout << "2. Play New Game" << endl;
    cout << "3. Load Previous Game" << endl;
    cout << "4. Add Command" << endl;
    cout << "5. Remove Command" << endl;
    cout << "6. Display All Commands" << endl;
    cout << "7. Save and Exit" << endl;
    cin >> this -> menuval;
}

void Game::printrules()
{
    system("cls");
    cout << "**** Game Rules ****" << endl;
    cout << "1. Each round you will be presented with a multiple choice question" << endl;
    cout << "Each question will ask for the purpose or results of a terminal command for linux (mint)" << endl;
    cout << "The points for each answer will be listed, if correct will be added to toal. If not will be subtracted" << endl;
    cout << "Negative numbers are possible, and answers will be saved under username" << endl;
    cout << "Try your best and learn well!" << endl;
}

void Game::printlist(List<Data> list)
{
    Node<Data>* pCur = list.getpHead();

    while(pCur != nullptr)
    {

        cout << pCur -> getdata() << endl;;
        pCur = pCur -> getpnext();
    }
    return;
}

void Game::filllist(List<Data> list) //will pull in lines and put them into a data var and insert until no lines
{
    this -> infile.open("commands.csv");
    Data tempdata;
    string tempstring;
    string token;
    
    if(this->infile.is_open())
    {
         while(getline(this -> infile, tempstring))
        {
            //get line and parce information into data class
            //code from my 122 pa 7 referenced for parcing data without strtok (as a string)

            //get command
            token = tempstring.substr(0, tempstring.find(',')); //create a substring
            tempstring.erase(0, tempstring.find(',') + 1); //erase all content until token
            tempdata.setcommand(token); //set command as string token derived from tempstring

            //get answer
            token = tempstring.substr(0, tempstring.find(',')); //create substring
            tempstring.erase(0, tempstring.find(',') + 1); //erase string content until ,
            tempdata.setanswer(token); //set the answer as the substring token gained

            //get points
            token = tempstring.substr(0, tempstring.find(',')); //create substring
            tempstring.erase(0, tempstring.find('\n') + 1); //erase rest of content
            tempdata.setpoints(stoi(token)); //set as integer interpetation of token

            this -> commandslist.insert(tempdata);
        }
    }
}