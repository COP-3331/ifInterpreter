/*
Alexander Dagama
U67010156
This header file defines the Story class.
*/

using namespace std;

#ifndef STORY__
#define STORY__

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>

#include "storytokenizer.h"
#include "passage.h"
#include "link.h"
#include "commands.h"
#include "plaintext.h"
#include "block.h"

class Story
{
    private:
        string fileName;
        vector<Passage*> passages;
        unordered_map<string, Passage*> passageMap; 
        unordered_map<string, bool> variableMap;
        
    public:
        Story(string fileName);
        void print();
        void play();
        void setVariable(string variable, bool value);
        bool getVariable(string variable);
};

#endif