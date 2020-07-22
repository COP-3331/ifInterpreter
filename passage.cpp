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

//Plays a passage, returns the name of the next Passage
string Passage::play(Story* storyRef)
{
    //call all the part's play functions
    for (unsigned int i = 0; i < parts.size(); i++)
    {
        string goToName = parts.at(i)->play(storyRef, this);

        //if a GOTO command is found, stop the passage and return the target
        if (goToName != "") return goToName;
    }

    //if no more links, return empty string to end program
    if (links.size() == 0) return "";

    //print all links and prompt user to choose a link
    cout << endl << endl << "Here are your options:" << endl;
    for (unsigned int i = 0; i < links.size(); i++)
        cout << i+1 << ". " << links.at(i)->getDisplay() << endl;
    
    int chosenLink;
    cout << endl << "Enter a link number: ";
    cin >> chosenLink;
    cout << endl;

    //return the chosen passage name
    return links.at(chosenLink-1)->getTarget();
}

void Passage::addPartPointer(Part* partPointer)
{
    parts.push_back(partPointer);
}

//used by the Link object to add a Link* to a passage
void Passage::addLinkPointer(Link* linkPointer)
{
    links.push_back(linkPointer);
}