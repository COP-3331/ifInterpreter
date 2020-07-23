#include "part.h"

//splits string on spaces and returns a vector of the tokens
vector<string> Part::splitOnSpace(string inputText)
{
    string token;
    vector<string> tokens;
    stringstream ss(inputText);
    while (ss >> token)
        tokens.push_back(token);
    return tokens;
}   
        
//converts strings to their respective boolean value
bool Part::stringToBool(string inputText)
{
    if (inputText == "true") return true;
    else if (inputText == "false") return false;
    else cout << "error parsing in stringToBool()" << endl;
    return false;
}

string Part::getType()
{
    return type;
}