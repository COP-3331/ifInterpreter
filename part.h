/*
Alexander Dagama
U67010156
This header file defines the Part class.
*/

#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

#ifndef PART
#define PART

class Part
{
    private:

    public:
        void print()
        {
            cout << "test" << endl;
        }
        void play();

        //splits string on spaces and returns a vector of the tokens
        vector<string> splitOnSpace(string inputText)
        {
            string token;
            vector<string> tokens;
            stringstream ss(inputText);
            while (ss >> token)
                tokens.push_back(token);
            return tokens;
        }

        //converts strings to their respective boolean value
        bool stringToBool(string inputText)
        {
            if (inputText == "true") return true;
            else if (inputText == "false") return false;
            else cout << "error parsing in stringToBool()" << endl;
            return false;
        }
};

#endif