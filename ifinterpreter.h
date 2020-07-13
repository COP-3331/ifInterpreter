/*
Alexander Dagama
U67010156
This header file defines the IFInterpreter class.
*/

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

using namespace std;

#ifndef IFINTERPRETER
#define IFINTERPRETER

class IFInterpreter
{
    private:
        string fileName;
        vector<Passage*> passages;
        unordered_map<string, Passage*> passageMap; 
        unordered_map<string, bool> variableMap;
        
    public:
        IFInterpreter(string fileName);
        void print();
};

#endif