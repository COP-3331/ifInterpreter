#include <iostream>
#include "plaintext.h"
using namespace std;

PlainText::PlainText(string inputText)
{
    type = "text";
    text = inputText;
}

void PlainText::print()
{
    cout << "Text: \"" << text << "\"" << endl;
}

string PlainText::play(Story* storyRef, Passage* passageRef)
{
    cout << text;
    return "";
}
