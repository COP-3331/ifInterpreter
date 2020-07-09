/*
Alexander Dagama
U67010156
This source file implements the fuctions of the PassageToken class.
*/

#include <iostream>
#include <string>
#include "passagetoken.h"

using namespace std;

PassageToken::PassageToken(string inputToken)
{
    //find index of delimiters
    int d1 = inputToken.find("name=\"") + 6;
    int d2 = inputToken.find("\"", d1);
    int d3 = inputToken.find(">", d2) + 1;
    int d4 = inputToken.find("<", d3);

    //extract the name and text
    name = inputToken.substr(d1, d2-d1);
    text = inputToken.substr(d3, d4-d3);
}

//returns the name of a PassageToken object
string PassageToken::getName() const
{
    return name;
}

//returns the text of a PassageToken object
string PassageToken::getText() const
{
    return text;
}