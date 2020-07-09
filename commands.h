/*
Alexander Dagama
U67010156
This header file defines the ElseIfCommand class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef COMMANDS
#define COMMANDS

class ElseCommand : public Part
{
    private:

    public:
        ElseCommand()
        {
            
        }
        
};

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