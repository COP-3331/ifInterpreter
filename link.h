/*
Alexander Dagama
U67010156
This header file defines the Link class.
*/

using namespace std;

#ifndef LINK__
#define LINK__

#include <string>
#include "part.h"

class Link : public Part
{
    private:
        string display;
        string target;

    public:
        Link(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
        string getDisplay() { return display; }
        string getTarget() { return target; }
};

#endif