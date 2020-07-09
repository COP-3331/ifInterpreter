/*
Alexander Dagama
U67010156
This header file defines the SetCommand class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef SETCOMMAND
#define SETCOMMAND

class SetCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        SetCommand(string inputText)
        {
            //TODO: seperate inputText into variable and value
        }
};

#endif