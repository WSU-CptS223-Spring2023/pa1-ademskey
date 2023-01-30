
#include "game.hpp"


using std::cout;
using std::endl;
using std::cin;

//game constructor
Game::Game(int input)
{ 
    this -> menuval = input;
}

//game destructor
Game::~Game()
{
    //inside destructor
}

//prints game menu
void Game::printmenu()
{
    system("clear");
    cout << "**** Welcome to the Linux Command Quiz!" << endl;
    cout << "1. Print Rules" << endl;
    cout << "2. Play New Game" << endl;
    cout << "3. Load Previous Game" << endl;
    cout << "4. Add Command" << endl;
    cout << "5. Remove Command" << endl;
    cout << "6. Display All Commands" << endl;
    cout << "7. Save and Exit" << endl;

}

//prints game rules
void Game::printrules()
{
    system("clear");
    cout << "**** Game Rules ****" << endl;
    cout << "1. Each round you will be presented with a multiple choice question" << endl;
    cout << "2. Each question will ask for the purpose or results of a terminal command for linux (mint)" << endl;
    cout << "3. The points for each answer will be listed, if correct will be added to toal. If not will be subtracted" << endl;
    cout << "4. Negative numbers are possible, and answers will be saved under username" << endl;
    cout << "5. Try your best and learn well!" << endl;
    cout << "press any button to continue" << endl;
    cin.get();
    cin.ignore();
}

//prints the contents of a list
void Game::printlist(List<Data> list)
{
    Node<Data>* pCur = list.getpHead();

    while(pCur != nullptr)
    {

        cout << pCur -> getdata() << endl;;
        pCur = pCur -> getpnext();
    }

    cin.ignore();
    std::cout << "Press any button to continue" << endl;
    std::cin.get();
}

//fills a linked list based on a file passed into it
void Game::filllist(List<Data> &list, string file) //will pull in lines and put them into a data var and insert until no lines
{
    this -> infile.open(file, std::ios::in);

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

            list.insert(tempdata);
        }

      this -> infile.close();
    }
}

//updates the files accociated with the list based on a filename passed in
void Game::updatelist(List<Data> list, string file)
{
    //open commands file to write
    this -> infile.open(file, std::ios::out);

    //initialize a pCur tracking variable
    Node<Data>* pCur = list.getpHead();
    Data tempdata;

    if(this -> infile.is_open())
    {
        //loop through list while writting commands to file
         while(pCur != nullptr)
        {
            //update tempdata
            tempdata = pCur -> getdata();

            //overwrite data useing overloaded operator into file
            infile << tempdata.getcommand();
            infile << ',';
            infile << tempdata.getanswer();
            infile << ',';
            infile << tempdata.getpoints() << endl;

            //incrament pCur
            pCur = pCur -> getpnext();
        }

        this -> infile.close(); //close infile
    }
}

//finds a player in a linked list and returns a integer representing success
int Game::findplayer(string name, List<Data> &userlist)
  {
    //initialize variables for pCur and tempdata
    Node<Data>* pCur = userlist.getpHead();
    Data tempdata;
    int success= 0;

    while(pCur != nullptr) //cycles through list of player modules
    {
        tempdata = pCur -> getdata(); //sets tempdata to the pCur data 

        if(tempdata.getanswer() == name) //if the name matches parameter, set game poitns to points
        {
            this -> pts = tempdata.getpoints();
            success = 1;
        }
    }
    if(success == 1)
    {
        cout << "User found, loading points" << endl;
    }
    else
    {
        cout << "Could not find user, points set to zero" << endl;
    }
    return success;
  }

//finds command in linked list and removes it
void Game::removecommand(List<Data> &commandslist)
{
    //initialize node tracking variables
    Node<Data>* pCur = commandslist.getpHead();
    Node<Data>* pPrev = nullptr;
    Node<Data>* pTemp = nullptr;

    //initialize variables for storing command and data
    int success = 0;
    string command;
    Data tempdata;

    //get command to be removed from user
    cin.ignore();
    cout << "Enter command to remove: ";
    getline(cin, command);

    while(pCur->getpnext() != nullptr) //while nodes exist
    {
        tempdata = pCur -> getdata(); //set tempdata to current's data

        if (tempdata.getcommand() == command) //if command matches
        {
            pTemp = pCur -> getpnext(); //set temp to next
            pPrev -> setpNext(pTemp); //set previous's next to temp
            pCur = pTemp;
            delete pTemp; //frees information stored in pCur
            success = 1;
        }
        else //if command doesnt match
        {
            //incrament trackers
            pCur = pCur -> getpnext();
            pPrev = pCur;
        }
    }
    if(success == 1){
        cout << "Removed command" << endl;
    }
    else{
        cout << "couldnt find command" << endl;
    }
    cout << "Press any key to continue" << endl;
    cin.get();
}

//gets info and inserts a node with new command 
void Game::addcommand(List<Data> &commandslist)
{
    //initialize variables to put in data
    string command, answer;
    int points;
    Data tempdata;

    //get relevant user input
    cout << "Enter command to be saved (No Spaces): ";
    cin >> command;
    tempdata.setcommand(command);

    cin.ignore();
    cout << "Enter command function: ";
    getline(cin, answer);
    tempdata.setanswer(answer);

    cout << "Enter ammount of points command is worth:";
    cin >> points;
    tempdata.setpoints(int(points));
    cout << "\n";
    
    //insert data into list
    commandslist.insert(tempdata);

    cout << "Command added!" << endl;
}

//finds number of nodes in linked list
int Game::size(List<Data> &commandslist)
{
    //initialize tracking information
    Node<Data>* pCur = commandslist.getpHead();
    int counter = 0;

    //circle through the list until a nullptr is detected
    while(pCur -> getpnext() != nullptr)
    {
        counter++; //incrament pNext
        pCur = pCur -> getpnext(); //incrament pCur
    }

    return counter; //return the ammount of nodes in the list
}

void Game::playgame(List<Data> &commandslist)
{
    //initialize node variables, data, and tracking integers
    Data answer, wrong1, wrong2, wrong3;
    char playeranswer;
    int numrounds, random1, random2, random3, random4, answernum, answernode, indexes_tracker; 
    int sizelist =  size(commandslist);
    int indexes[50] = {};

    //seed rand
    srand(time(0));

    //get number of rounds that player would like to play
    cout << "Enter number of rounds you would like to play: ";
    cin >> numrounds;

    // get questions for the number of rounds player has requested
    for(int i = 0; i < numrounds; i++)
    {
        //generate random numbers for choosing questions
        random1 = rand() % sizelist;
        random2 = rand() % sizelist;
        answernode = rand() % sizelist;
        answernum = rand() % 3;

        //get data for the wrong answers
        answer = this -> dataindex(answernode, commandslist);
        wrong1 = this -> dataindex(random1, commandslist);
        wrong2 = this -> dataindex(random2, commandslist);

        //print points to the user
        std::cout << "\n***********************************************" << endl;
        std::cout << "Player Current points: " << this -> pts << endl;
        std::cout << "\n***********************************************" << endl;

        //ask question with answer position based o
        switch(answernum)
        {
            case 1:

                cout << "What does the function " << answer.getcommand() << "do?" << endl;
                cout << "A: " << answer.getanswer()<< endl;
                cout << "b: " << wrong1.getanswer()<< endl;
                cout << "c: " << wrong2.getanswer() << endl;

                std::cin >> playeranswer;
                if(playeranswer == 'a' || playeranswer == 'A')
                {
                    cout << "You are correct, " << answer.getpoints() << " points have been added to your score" << endl;
                    this -> pts += answer.getpoints();
                    cout << "You now have " << answer.getpoints() << "points" << endl;
                }
                else
                {
                    cout << "You were incoreect, " << answer.getpoints() << "has been subtracted" << endl;
                    this -> pts -= answer.getpoints();
                    cout << "You now have " << answer.getpoints() << "points" << endl;
                }
                break;

            case 2:

                cout << "What does the function " << answer.getcommand() << " do?" << endl;
                cout << "A: " << wrong1.getanswer()<< endl;
                cout << "b: " << answer.getanswer() << endl;
                cout << "c: " << wrong2.getanswer()<< endl;

                std::cin >> playeranswer;
                if(playeranswer == 'b' || playeranswer == 'B')
                {
                    cout << "You are correct, " << answer.getpoints() << " has been added to your score" << endl;
                    this -> pts += answer.getpoints();
                    cout << "You now have " << answer.getpoints() << " points" << endl;
                }
                else
                {
                    cout << "You were incoreect, " << answer.getpoints() << " has been subtracted" << endl;
                    this -> pts -= answer.getpoints();
                    cout << "You now have " << answer.getpoints() << " points" << endl;
                }
                break;

            case 3:

                cout << "What does the function " << answer.getcommand() << " do?" << endl;
                cout << "A: " << wrong1.getanswer()<< endl;
                cout << "b: " << wrong2.getanswer()<< endl;
                cout << "c: " << answer.getanswer() << endl;

                std::cin >> playeranswer;
                if(playeranswer == 'c' || playeranswer == 'C')
                {
                    cout << "You are correct, " << answer.getpoints() << " has been added to your score" << endl;
                    this -> pts += answer.getpoints();
                    cout << "You now have " << answer.getpoints() << " points" << endl;
                }
                else
                {
                    cout << "You were incoreect, " << answer.getpoints() << " has been subtracted" << endl;
                    this -> pts -= answer.getpoints();
                    cout << "You now have " << answer.getpoints() << " points" << endl;
                }
                break;

            default:
                cout << "Something went wrong, computer error" << endl;
                break;
        }
    }
    cout << "Game has ended, score will be updated for profile when save and exit is selected" << endl;
    cout << "Press any button to continue" << endl;
    cin.get();
}

Data Game::dataindex(int index, List<Data> &commandslist)
{
    Node<Data>* pCur = commandslist.getpHead();
    Data returndata;

    if(pCur -> getpnext())
    {
        for (int i = 0; i <= index; i++)
        {
            if(i == index)
            {
                returndata = pCur -> getdata();
                pCur = pCur -> getpnext(); //incrament pCur
            }
            else
            {
                pCur = pCur -> getpnext(); //incrament pCur
            }
        }
    }
    return returndata;
}

void Game::adduser(List<Data> &userlist)
{
    //initialize name variables
    string playername, lastname;

    //get full name
    cout << "Enter firstname" << endl;
    std::cin >> playername;
    cout << "Enter lastname" << endl;
    std::cin >> lastname;

    //create data with information
    Data newplayer(lastname, playername, 0);
    userlist.insert(newplayer);

}