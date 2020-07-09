/*
Alexander Dagama
U67010156
This source file implements the functions of the StoryTokenizer class.
*/

#include <iostream>
#include <string>
#include <vector>
#include "storytokenizer.h"

using namespace std;

StoryTokenizer::StoryTokenizer(string inputText)
{
    //loop while file still contains delimiters
    while (inputText.find("<tw-passagedata") != string::npos && inputText.find("</tw-passagedata>") != string::npos)
    {
        //get index of delimiters
        int d1 = inputText.find("<tw-passagedata");
        int d2 = inputText.find("</tw-passagedata>") + 17;

        //extract and erase substring of a single passage
        string token = inputText.substr(d1, d2 - d1);
        inputText.erase(d1, d2 - d1);

        //create PassageToken object and add to passageList vector
        passageList.push_back(PassageToken(token));
    }
}

//returns a boolean indicating if there is a next passage
bool StoryTokenizer::hasNextPassage() const
{
    return passageList.size() != 0;
}

//returns the next PassageToken object
PassageToken StoryTokenizer::nextPassage()
{
    if (passageList.size() == 0) return PassageToken("");

    //get first PassageToken in passageList vector
    PassageToken nextToken = passageList.at(0);

    //remove same PassageToken from passageList vector
    passageList.erase(passageList.begin());

    return nextToken;
}