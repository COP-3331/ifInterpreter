#include "part.h"
#include "passage.h"

class Block : public Passage, public Part
{
    public:
        Block(string inputText);
        void print();
};