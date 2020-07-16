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
    public:
    void print();
        
};

class ElseIfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        ElseIfCommand(string inputText);
        void print();
        
};

class GoToCommand : public Part
{
    private:
        string target;

    public:
        GoToCommand(string inputText);
        void print();
        
};

class IfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        IfCommand(string inputText);
        void print();
};

class SetCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        SetCommand(string inputText);
        void print();
};

#endif