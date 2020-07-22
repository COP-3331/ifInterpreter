/*
Alexander Dagama
U67010156
This header file defines the PartToken class.
*/

#include <string>

using namespace std;

#ifndef PART_TOKEN
#define PART_TOKEN

enum partType {LINK, SET, GOTO, IF, ELSEIF, ELSE, BLOCK, TEXT};

class PartToken
{
    private:
        partType type;
        string text;
    public:
        PartToken(partType type, string text);
        partType getType() const;
        string getText() const;
};

#endif