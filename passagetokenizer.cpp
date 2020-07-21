/*
Alexander Dagama
U67010156
This source file implements the functions of the PassageTokenizer class.
*/

#include <iostream>
#include "passagetokenizer.h"

using namespace std;

PassageTokenizer::PassageTokenizer(string inputText)
{
    while(true)
    {
        partType type;
        int endDelim;

        //get index of delimiters
        int b1 = inputText.find("[");
        int b2 = inputText.find("(go-to:");
        int b3 = inputText.find("(set:");
        int b4 = inputText.find("(if:");
        int b5 = inputText.find("(else-if:");
        int b6 = inputText.find("(else:");

        //if delim not found
        if (b1 == -1) b1 = inputText.length();
        if (b2 == -1) b2 = inputText.length();
        if (b3 == -1) b3 = inputText.length();
        if (b4 == -1) b4 = inputText.length();
        if (b5 == -1) b5 = inputText.length();
        if (b6 == -1) b6 = inputText.length();

        //get first index of a delimitters
        int inputLength = inputText.length();
        int startDelim = min(b1, min(b2, min(b3, min(b4, min(b5, b6)))));

        //if no delims found, create and add partToken with remaining text
        if (startDelim == inputLength)
        {
            if (inputLength > 0) partList.push_back(PartToken(TEXT, inputText));
            break;
        }

        //get type of PartToken and index of ending delim
        if (startDelim == b1) 
        {
            if (inputText.at(b1+1) == '[')
            {
                type = LINK;
                endDelim = inputText.find("]]", startDelim)+1;
            }
            else
            {
                type = BLOCK;
                int blockDepth = 1;
                unsigned int i;
                for (i = b1+1; i < inputText.length(); i++)
                {
                    if (inputText.at(i) == '[') blockDepth++;
                    if (inputText.at(i) == ']') blockDepth--;
                    if (blockDepth == 0) break;
                }
                endDelim = i;
            }
        }
        else if (startDelim == b2)
        {
            type = GOTO;
            endDelim = inputText.find(")", startDelim);
        }

        else if (startDelim == b3)
        {
            type = SET;
            endDelim = inputText.find(")", startDelim);
        }

        else if (startDelim == b4)
        {
            type = IF;
            endDelim = inputText.find(")", startDelim);
        }

        else if (startDelim == b5)
        {
            type = ELSEIF;
            endDelim = inputText.find(")", startDelim);
        }

        else if (startDelim == b6)
        {
            type = ELSE;
            endDelim = inputText.find(")", startDelim);
        }
        
        else
        {
            type = TEXT;
            endDelim = inputText.find(")", startDelim);
            cout << "ERROR: Wasn't able to determine partToken type" << endl;
        }
        
        //create and add token from text before delim
        string beforeToken;
        if (startDelim > 0)
        {
            beforeToken = inputText.substr(0, startDelim);
            inputText.erase(0, startDelim);

            //fix indexes after erasing
            startDelim -= beforeToken.length();
            endDelim -= beforeToken.length();

            partList.push_back(PartToken(TEXT, beforeToken));
        }


        //Create and add token from found partToken
        string afterToken = inputText.substr(startDelim, endDelim+1);
        inputText.erase(startDelim, endDelim+1);
        partList.push_back(PartToken(type, afterToken));
        
    }
}

bool PassageTokenizer::hasNextPart() const
{
    return partList.size() != 0;
}

PartToken PassageTokenizer::nextPart()
{
    if (partList.size() == 0) return PartToken(TEXT, "");

    //get first PartToken in partList vector
    PartToken nextToken = partList.at(0);

    //remove same PartToken from partList vector
    partList.erase(partList.begin());

    return nextToken;
}