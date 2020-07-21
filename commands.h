/*
Alexander Dagama
U67010156
This header file defines the ElseIfCommand class.
*/

using namespace std;

#ifndef COMMANDS
#define COMMANDS

#include <string>
#include <vector>
#include <sstream>
#include "part.h"
#include "story.h"

class ElseCommand : public Part
{
    public:
        ElseCommand();
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

class ElseIfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        ElseIfCommand(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
        
};

class GoToCommand : public Part
{
    private:
        string target;

    public:
        GoToCommand(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

class IfCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        IfCommand(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

class SetCommand : public Part
{
    private:
        string variable;
        bool value;

    public:
        SetCommand(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

#endif