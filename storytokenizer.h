/*
Alexander Dagama
U67010156
This header file defines the StoryTokenizer class.
*/

#include <string>
#include <vector>
#include "passagetoken.h"
#include "parttoken.h"
#include "passagetokenizer.h"

using namespace std;

#ifndef STORY_TOKENIZER
#define STORY_TOKENIZER

class StoryTokenizer
{
    private:
        vector<PassageToken> passageList;
    public:
        StoryTokenizer(string inputText);
        bool hasNextPassage() const;
        PassageToken nextPassage();
};

#endif