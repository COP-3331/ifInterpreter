/*
Alexander Dagama
U67010156
This header file defines the ElseIfCommand class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef ELSEIFCOMMAND
#define ELSEIFCOMMAND

class ElseIfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        ElseIfCommand(string inputText)
        {
            //TODO: seperate inputText into variable and value
        }
        
};

#endif