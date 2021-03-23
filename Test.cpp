#include "doctest.h"
#include "Board.hpp"
using namespace ariel;

#include "Direction.hpp"
#include <iostream>
#include <string>
using namespace std;

TEST_CASE("Good case!"){
    ariel::Board a;
    CHECK(a.read(20,25, Direction::Vertical,3) == "___");
    CHECK(a.read(20,25, Direction::Horizontal,6) == "______");
    CHECK_NOTHROW(a.post(15,20,Direction::Vertical,"Hello"));
    CHECK(a.read(15,20, Direction::Vertical,3) == "Hel");
    CHECK(a.read(15,20, Direction::Horizontal,6) == "H_____");
    CHECK(a.read(15,20, Direction::Vertical,6) == "Hello_");
    CHECK(a.read(13,20, Direction::Vertical,8) == "__Hello_");
    CHECK_NOTHROW(a.post(15,20,Direction::Horizontal,"ONEPIECE"));
    CHECK(a.read(15,20, Direction::Vertical,5) == "Oello");
    CHECK(a.read(15,21, Direction::Vertical,5) == "n____");
    CHECK_NOTHROW(a.post(14,21,Direction::Vertical,"GEEKSFORGEEKS"));
    CHECK(a.read(16,20, Direction::Horizontal,2) == "eE");
    CHECK(a.read(19,20, Direction::Horizontal,2) == "oS");
    CHECK(a.read(15,20, Direction::Vertical,9) == "OGEPIECE");
    CHECK(a.read(15,20, Direction::Vertical,8) == "OGEPIEC");
    CHECK_NOTHROW(a.post(14,21,Direction::Vertical,""));
    CHECK(a.read(14,21, Direction::Vertical,1) == "G");
    CHECK(a.read(14,21, Direction::Vertical,0) == "");
}
TEST_CASE("Checking what not supposed to be."){
    ariel::Board b;
    CHECK(b.read(15,20, Direction::Vertical,3) != "abc");
    CHECK_NOTHROW(b.post(3,3,Direction::Vertical, "Hello"));
    CHECK_NOTHROW(b.post(5,3,Direction::Vertical,"World"));
    CHECK(b.read(3,3, Direction::Vertical,5) != "Hello"); // supposed to be "HeWor"
    CHECK_NOTHROW(b.post(5,3,Direction::Horizontal,"Gnom")); 
    CHECK(b.read(5,3, Direction::Horizontal,5) != "Wnom_"); // supposed to be "Gnom_"
    CHECK_NOTHROW(b.post(4,5,Direction::Vertical,"Bellic")); 
    CHECK_NOTHROW(b.post(6,1,Direction::Horizontal,"Monster"));
    CHECK_NOTHROW(b.post(200,200,Direction::Horizontal,"Wii"));
    CHECK(b.read(4,5, Direction::Vertical,6) != "Bellic");// supposed to be "Betlic"
    CHECK(b.read(5,3, Direction::Horizontal,4) != "Gnom");// supposed to be "Gnem"
}

