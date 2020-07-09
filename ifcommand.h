/*
Alexander Dagama
U67010156
This header file defines the IfCommand class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef IFCOMMAND
#define IFCOMMAND

class IfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        IfCommand(string inputText)
        {
            //TODO: seperate inputText into variable and value
        }
};

#endif