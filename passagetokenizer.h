/*
Alexander Dagama
U67010156
This header file defines the PassageTokenizer class.
*/
#include <vector>
#include <string>
#include "parttoken.h"

using namespace std;

#ifndef PASSAGE_TOKENIZER
#define PASSAGE_TOKENIZER

class PassageTokenizer
{
    private:
        vector<PartToken> partList;
    public:
        PassageTokenizer(string inputText);
        bool hasNextPart() const;
        PartToken nextPart();
};

#endif