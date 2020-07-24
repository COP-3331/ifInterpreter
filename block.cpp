#include <iostream>
#include "block.h"
#include "link.h"
#include "commands.h"
#include "plaintext.h"
#include "passagetokenizer.h"
using namespace std;

Block::Block(string inputText):Passage(inputText)
{
    type = "block";
    inputText = inputText.substr(1,inputText.size()-2);
    PassageTokenizer tokenizer(inputText);
    while(tokenizer.hasNextPart())
    {
        PartToken stok = tokenizer.nextPart();
        Part* partPointer;
        switch (stok.getType())
        {
            case LINK:
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
                partPointer = new Block(stok.getText());
                break;
            case TEXT:
                partPointer = new PlainText(stok.getText());
                break;
            default:
                cout << "  ERROR: can't determine token type  " << endl;
        }
        addPartPointer(partPointer);
    }
}

void Block::print()
{
    cout << "START BLOCK\n";
    for(unsigned int i=0;i<parts.size();i++)
    {
        (parts.at(i))->print();
    }
    cout << "END BLOCK" << endl;
}

string Block::play(Story* storyRef, Passage* passageRef)
{
    bool enterBlock = false;
    bool doElseIfElse = false;

    //call all the part's play functions
    for (unsigned int i = 0; i < parts.size(); i++)
    {
        string result = "";
        if (parts.at(i)->getType() != "block")
            result = parts.at(i)->play(storyRef, passageRef);
        else if (parts.at(i)->getType() == "block" && enterBlock)
        {
            result = parts.at(i)->play(storyRef, passageRef);
            enterBlock = false;
        }

        //if a GOTO command is found, stop the passage and return the target
        if (parts.at(i)->getType() == "goto" && result != "") return result;

        //If-elseIf-Else logic
        else if (parts.at(i)->getType() == "if" && result == "1") 
        {
            enterBlock = true;
            doElseIfElse = false;
        }
        else if (parts.at(i)->getType() == "if" && result == "0")
        {
            doElseIfElse = true;
        }
        else if (parts.at(i)->getType() == "else-if" && result == "1" && doElseIfElse)
        {
            enterBlock = true;
            doElseIfElse = false;
        }
        else if (parts.at(i)->getType() == "else-if" && result == "0" && doElseIfElse)
        {
            doElseIfElse = true;
        }
        else if (parts.at(i)->getType() == "else" && doElseIfElse)
        {
            enterBlock = true;
        }
        
    }

    //if no more links, return empty string to end program
    if (links.size() == 0) return "";

    //print all links and prompt user to choose a link
    cout << endl << endl << "Here are your options:" << endl;
    for (unsigned int i = 0; i < links.size(); i++)
        cout << i+1 << ". " << links.at(i)->getDisplay() << endl;
    
    int chosenLink;
    cout << endl << "Enter the number of your decision: ";
    cin >> chosenLink;
    cout << endl;

    //return the chosen passage name
    string chosenPassage = links.at(chosenLink-1)->getTarget();
    return chosenPassage;
}