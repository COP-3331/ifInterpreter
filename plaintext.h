/*
Alexander Dagama
U67010156
This header file defines the PlainText class.
*/

#include <string>
#include "part.h"

using namespace std;

#ifndef PLAINTEXT
#define PLAINTEXT

class PlainText : public Part
{
    private:
        string text;
    public:
        PlainText(string inputText)
        {
            text = inputText;
        }
        
};

#endif