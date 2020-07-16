/*
Alexander Dagama
U67010156
This source file implements the functions of the Passage class.
*/

#include "passage.h"
#include <iostream>

using namespace std;

Passage::Passage(string name)
{
    this->name = name;
}

void Passage::print()
{
    cout << "Passage " << name << ":" << endl;
    for (unsigned int i = 0; i < parts.size(); i++)
        parts.at(i)->print();
}

void Passage::play()
{

}

void Passage::addPartPointer(Part* partPointer)
{
    parts.push_back(partPointer);
}