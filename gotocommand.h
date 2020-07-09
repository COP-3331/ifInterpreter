/*
Alexander Dagama
U67010156
This header file defines the GoToCommand class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef GOTOCOMMAND
#define GOTOCOMMAND

class GoToCommand : public Part
{
    private:
        string target;

    public:
        GoToCommand(string inputText)
        {
            target = inputText;
        }
        
};

#endif