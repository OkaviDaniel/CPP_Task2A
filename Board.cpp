#include "Board.hpp"
using namespace ariel;
#include <iostream>
using namespace std;
#include <climits>

ariel::Board::Board()
{
    this->b = "New Board";
}

void ariel::Board::post(unsigned int row, unsigned int col, Direction d,const string &message)
{
    if(((row + message.length()) > UINT_MAX) && d==Direction::Vertical){
        cout << "err(row + msg_len = " << row << "+" << message.length() << "="<< (row+message.length()) << ")" <<endl;
        throw out_of_range{"You are trying to post in a place that you can't have access.\n"};
    }
    if(((col + message.length()) > UINT_MAX) && d==Direction::Horizontal){
        cout << "err(col + msg_len = " << col << "+" << message.length() << "="<< (col+message.length()) << ")" <<endl;
        throw out_of_range{"You are trying to post in a place that you can't have access.\n"};
    }
    this->b = message;
}

string ariel::Board::read(unsigned int row, unsigned int col, Direction d, unsigned int len)
{
    if(((row + (size_t)len > UINT_MAX) && d==Direction::Vertical)){
        cout << "err(row + len = " << row << "+" << (size_t)len << "="<< (row+(size_t)len) << ")" <<endl;
        throw out_of_range{"You are trying to read in a place that you don't have access to read.\n"};
    }
    if(((col + (size_t)len > UINT_MAX) && d==Direction::Horizontal)){
        cout << "err(col + len = " << col << "+" << (size_t)len << "="<< (col+(size_t)len) << ")" <<endl;
        throw out_of_range{"You are trying to read in a place that you don't have access to read.\n"};
    }
    if(len == 0){
        return "";
    }
    return "Ariel\n";
}
void ariel::Board::show()
{
    cout << "Ariel\n";
}
