/*
Alexander Dagama
U67010156
This header file defines the PlainText class.
*/

using namespace std;

#ifndef PLAINTEXT
#define PLAINTEXT

#include <string>
#include "part.h"

class PlainText : public Part
{
    private:
        string text;
    public:
        PlainText(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

#endif