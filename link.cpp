#include <iostream>
#include "link.h"
using namespace std;

Link::Link(string inputText)
{
    //remove outside brackets
    inputText = inputText.substr(2, inputText.length()-4);
    int d1 = inputText.find("-&gt;");
    //check if link has different display name
    if (d1 == -1)
    {
        display = inputText;
        target = inputText;
    }
    else 
    {
        display = inputText.substr(0, d1);
        target = inputText.substr(d1+5);
    }
}

void Link::print(){
    cout << "Link: display=" << display << ", target=" << target << endl;
}