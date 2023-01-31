#include "data.hpp"

std::ostream& operator << (std::ostream& lhs, Data rhs)
{
    std::cout << "Command:";
    std::cout << rhs.getcommand() << std::endl;
    std::cout << "Answer: ";
    std::cout << rhs.getanswer() << std::endl;
    std::cout << "Points: ";
    std::cout << rhs.getpoints() << std::endl;
    return lhs;
}
std::ofstream& operator << (std::ofstream& lhs, Data rhs)
{
    string csv = ",";
    string points = std::to_string(rhs.getpoints());
    string command, answer;
    command = rhs.getcommand();
    answer = rhs.getanswer();

    lhs << command;
    lhs << csv;
    lhs << answer;
    lhs << csv;
    lhs << points;

    return lhs;
}