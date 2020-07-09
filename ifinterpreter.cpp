/*
Alexander Dagama
U67010156
This source file implements the functions of the IFInterpreter class.
*/

#include "ifinterpreter.h"

using namespace std;

IFInterpreter::IFInterpreter(string fileName)
{
    this->fileName = fileName;

    string line;
    string story;

    //Open input.txt for reading
    ifstream in(fileName);
    if (!in.is_open())
    {
        cout << "Couldn't open " << fileName << " for reading!\n";
        return;
    }

    //Read in the story from input.txt
    getline(in, line);
    while (in && line != "</html>")
    {
        story += line + '\n';
        getline(in, line);
    }

    //Construct the StoryTokenizer object
    StoryTokenizer st(story);

    //Iterate through all of the passages in the story
    int pass = 0;
    while (st.hasNextPassage())
    {
        //Use the PassageToken to construct a PassageTokenizer
        PassageToken ptok = st.nextPassage();
        PassageTokenizer pt(ptok.getText());

        //create a passage object
        Passage* currPassage = new Passage(ptok.getName());

        //Iterate through all of the parts of the passage
        while (pt.hasNextPart())
        {
            PartToken stok = pt.nextPart();

            //create pointer to part that will be added
            Part* partPointer;

            switch (stok.getType())
            {
                case LINK2:
                    partPointer = new Link(stok.getText());
                    break;
                case SET:
                    partPointer = new SetCommand(stok.getText());
                    break;
                case GOTO:
                    partPointer = new GoToCommand(stok.getText());
                    break;
                case IF:
                    partPointer = new IfCommand(stok.getText());
                    break;
                case ELSEIF:
                    partPointer = new ElseIfCommand(stok.getText());
                    break;
                case ELSE:
                    partPointer = new ElseCommand();
                    break;
                case BLOCK:
                    //TODO: Implement Block
                    break;
                case TEXT:
                    partPointer = new PlainText(stok.getText());
                    break;
                default:
                    cout << "  ERROR: can't determine token type  " << endl;
            }

            //add partPointer to the Passage
            currPassage->addPartPointer(partPointer);
        }

        //add currPassage to passages vector and passageMap
        passages.push_back(currPassage);
        passageMap[ptok.getName()] = currPassage;
    }
}

void IFInterpreter::print()
{
    for(int i = 0; i < passages.size(); i++)
        passages.at(i)->print();
}