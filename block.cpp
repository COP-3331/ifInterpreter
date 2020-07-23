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
    return Passage::play(storyRef);
}