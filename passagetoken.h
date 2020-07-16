/*
Alexander Dagama
U67010156
This header file defines the PassageToken class.
*/

using namespace std;
#include <string>

#ifndef PASSAGE_TOKEN
#define PASSAGE_TOKEN

class PassageToken
{
    private:
        string name;
        string text;
    public:
        PassageToken(string inputToken);
        string getName() const;
        string getText() const;
};

#endif