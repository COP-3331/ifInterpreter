/*
Alexander Dagama
U67010156
This header file defines the Part class.
*/

#include <string>
#include <iostream>

using namespace std;

#ifndef PART
#define PART

class Part
{
    private:

    public:
        void print()
        {
            cout << "test" << endl;
        }
        void play();
};

#endif