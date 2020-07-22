using namespace std;

#ifndef BLOCK__
#define BLOCK__

#include "part.h"
#include "passage.h"

class Block : public Passage, public Part
{
    public:
        Block(string inputText);
        void print();
        string play(Story* storyRef, Passage* passageRef);
};

#endif