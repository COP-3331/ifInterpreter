/*
Alexander Dagama
U67010156
This header file defines the Link class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef LINK
#define LINK

class Link : public Part
{
    private:
        string display;
        string target;

    public:
        Link(string inputText);
        void print();
};

#endif