
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
    cout << "**** Welcome to the Linux Command Quiz!" << endl;
    cout << "1. " << endl;
    cout << "2. " << endl;
    cout << "3. " << endl;
    cout << "4. " << endl;
    cout << "5. " << endl;
    cout << "6. " << endl;
    cout << "7. " << endl;
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
    return;
}