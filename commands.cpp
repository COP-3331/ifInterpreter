#include <iostream>
#include "commands.h"
using namespace std;

GoToCommand::GoToCommand(string inputText)
{
    type = "goto";
    int d1 = inputText.find("&quot;")+6;
    int d2 = inputText.find("&quot;", d1+1);
    target = inputText.substr(d1, d2-d1);
}

void GoToCommand::print()
{
    cout << "Goto: target=" << target << endl;
}

//returns the target of the GoToCommand
string GoToCommand::play(Story* storyRef, Passage* passageRef)
{
    return target;
}

SetCommand::SetCommand(string inputText)
{
    type = "set";
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void SetCommand::print()
{
    cout << "Set: var=" << variable << ", value=" << (value ? "true":"false") <<endl;
}

//sets a variable in the Story object
string SetCommand::play(Story* storyRef, Passage* passageRef)
{
    storyRef->setVariable(variable, value);
    return "";
}

IfCommand::IfCommand(string inputText)
{
    type = "if";
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void IfCommand::print()
{
    cout << "If: var=" << variable << ", value=" << (value ? "true":"false") << endl;
}

string IfCommand::play(Story* storyRef, Passage* passageRef)
{
    bool variableBool = storyRef->getVariable(variable);
    return (variableBool == value ? "1" : "0");
}

ElseIfCommand::ElseIfCommand(string inputText)
{
    type = "else-if";
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void ElseIfCommand::print()
{
    cout << "Else-if: var=" << variable << ", value=" << value << endl;
}

string ElseIfCommand::play(Story* storyRef, Passage* passageRef)
{
    
    bool variableBool = storyRef->getVariable(variable);
    return (variableBool == value ? "1" : "0");
}

ElseCommand::ElseCommand()
{
    type="else";
}

void ElseCommand::print()
{
    cout << "Else" << endl;
}

string ElseCommand::play(Story* storyRef, Passage* passageRef)
{
    return "";
}