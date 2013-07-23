#include "resource.h"

void Lexxer::generateTokens(std::string raw)
{
    tokens.clear();
    tokens.push_back("__BEGIN");
    unsigned int pos=0;
    raw=" "+raw;
    while(pos!=std::string::npos)
    {
        unsigned int epos=raw.find_first_of(" \"", pos+1);
        if(epos==std::string::npos)
        {
            tokens.push_back(raw.substr(pos+1, epos-pos-1));
        }
        else if(raw[epos]=='"')
        {
            tokens.push_back(raw.substr(epos+1, raw.find("\"", epos+1)-epos-1));
        }
        else
        {
            tokens.push_back(raw.substr(pos+1, epos-pos-1));
        }
        pos=epos;
    }
    current_token=0;
}

std::string Lexxer::getNextToken()
{
    if(current_token==static_cast<int>(tokens.size()))
    {
        return "__END";
    }
    return tokens[current_token++];
}
