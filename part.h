/*
Alexander Dagama
U67010156
This header file defines the Part class.
*/

using namespace std;

#ifndef PART
#define PART

#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <unordered_map>

class Passage;
class Story;

class Part
{
    protected:
        string type;
    public:
        virtual void print(){};
        virtual string play(Story* storyRef, Passage* passageRef){};
        vector<string> splitOnSpace(string inputText);
        bool stringToBool(string inputText);
};

#endif