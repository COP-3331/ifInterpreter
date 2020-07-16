/*
Alexander Dagama
U67010156
This header file defines the Part class.
*/

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#ifndef PART
#define PART

class Part
{
    private:

    public:
    virtual void print(){};
    void play();
    vector<string> splitOnSpace(string inputText);
    bool stringToBool(string inputText);
};

#endif