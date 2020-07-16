#include <iostream>
#include "commands.h"
using namespace std;

GoToCommand::GoToCommand(string inputText)
{
    int d1 = inputText.find("&quot;")+6;
    int d2 = inputText.find("&quot;", d1+1);
    target = inputText.substr(d1, d2-d1);
}

void GoToCommand::print()
{
    cout << "Goto: target=" << target << endl;
}

SetCommand::SetCommand(string inputText)
{
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void SetCommand::print()
{
    cout << "Set: var=" << variable << ", value=" << (value ? "true":"false") <<endl;
}

IfCommand::IfCommand(string inputText)
{
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void IfCommand::print()
{
    cout << "If: var=" << variable << ", value=" << (value ? "true":"false") << endl;
}

ElseIfCommand::ElseIfCommand(string inputText)
{
    vector<string> tokens = splitOnSpace(inputText);
    variable = tokens[1];
    value = stringToBool(tokens[3].substr(0, tokens[3].length()-1));
}

void ElseIfCommand::print()
{
    cout << "Else-if: var=" << variable << ", value=" << value << endl;
}

void ElseCommand::print()
{
    cout << "Else" << endl;
}