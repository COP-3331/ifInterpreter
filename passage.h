/*
Alexander Dagama
U67010156
This header file defines the Passage class.
*/

#include <string>
#include <vector>
#include "part.h"

using namespace std;

#ifndef PASSAGE
#define PASSAGE

class Passage
{
    private:
        string name;
    protected:    
        vector<Part*> parts;
    public:
        Passage(string name);
        void print();
        void play();
        void addPartPointer(Part* partPointer);
};

#endif