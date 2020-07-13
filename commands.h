/*
Alexander Dagama
U67010156
This header file defines the ElseIfCommand class.
*/

#include <string>
#include <vector>
#include <sstream>
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
            vector<string> tokens = splitOnSpace(inputText);
            variable = tokens[1];
            value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
        }
        
};

class GoToCommand : public Part
{
    private:
        string target;

    public:
        GoToCommand(string inputText)
        {
            int d1 = inputText.find("&quot;")+6;
            int d2 = inputText.find("&quot;", d1+1);

            target = inputText.substr(d1, d2-d1);
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
            vector<string> tokens = splitOnSpace(inputText);
            variable = tokens[1];
            value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
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
            vector<string> tokens = splitOnSpace(inputText);
            variable = tokens[1];
            value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
        }
};

#endif