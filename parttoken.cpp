/*
Alexander Dagama
U67010156
This source file implements the functions of the PartToken class.
*/

#include "parttoken.h"

using namespace std;

PartToken::PartToken(partType type, string text)
{
    this->type = type;
    this->text = text;
}

partType PartToken::getType() const
{
    return type;
}

string PartToken::getText() const
{
    return text;
}