/*
Alexander Dagama
U67010156
This header file defines the Passage class.
*/

using namespace std;

#ifndef PASSAGE
#define PASSAGE

#include <string>
#include <vector>
#include "part.h"
#include <unordered_map>
#include <typeinfo>
#include "link.h"

class Passage
{
    private:
        string name;
    protected:    
        vector<Part*> parts;
        vector<Link*> links;
    public:
        Passage(string name);
        friend class Part;
        void print();
        string play(Story* storyRef);
        void addPartPointer(Part* partPointer);
        void addLinkPointer(Link* linkPointer);
};

#endif