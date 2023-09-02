/*include custom headers */
#include "string_helper.h"

vector<string> split (const string &s , char delimiter)
{
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream , token , delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}