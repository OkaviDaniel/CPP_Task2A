#include <iostream>
#include "Direction.hpp"
using namespace std;

namespace ariel
{
    class Board
    {
    string b;
    public:
        Board();
        void post(unsigned int row, unsigned int col, Direction d, const string &message);
        static string read(unsigned int row, unsigned int col, Direction d, unsigned int len);
        static void show();
    };
}