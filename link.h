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
        Link(string inputText)
        {
            //remove outside brackets
            inputText = inputText.substr(2, inputText.length()-4);
            int d1 = inputText.find("-&gt;");

            //check if link has different display name
            if (d1 == -1)
            {
                display = inputText;
                target = inputText;
            }
            else 
            {
                display = inputText.substr(0, d1);
                target = inputText.substr(d1+5);
            }
        }
};

#endif