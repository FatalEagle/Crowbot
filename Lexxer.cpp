#include "resource.h"

void Lexxer::generateTokens(std::string raw)
{
    tokens.clear();
    tokens.push_back("__BEGIN");
    raw=" "+raw;
    unsigned int pos=0;
    unsigned int epos=raw.find_first_of(" \"(", pos+1);
    std::string possible_token;
    while(epos!=std::string::npos)
    {
        if(epos==std::string::npos)
        {
            possible_token=raw.substr(pos+1, epos-pos-1);
            pos=epos;
        }
        else if(raw[epos]=='"')
        {
            unsigned int qpos=raw.find("\"", epos+1);
            possible_token=raw.substr(epos+1, qpos-epos-1);
            pos=qpos;
        }
        else if(raw[epos]=='(')
        {
            unsigned int ppos=raw.find(")", epos+1);
            tokens.push_back("__FUNC");
            tokens.push_back(raw.substr(pos+1, epos-pos-1));
            possible_token=raw.substr(epos+1, ppos-epos-1);
            unsigned int spos;
            while(!possible_token.empty())
            {
                spos=possible_token.find(",");
                tokens.push_back(possible_token.substr(0, spos));
                possible_token.erase(0, spos+1);
                while(!possible_token.empty() && possible_token[0]==' ')
                {
                    possible_token.erase(0, 1);
                }
            }
            pos=ppos;
        }
        else
        {
            possible_token=raw.substr(pos+1, epos-pos-1);
            pos=epos;
        }
        epos=raw.find_first_of(" \"(", pos+1);
        if(!possible_token.empty())
        {
            tokens.push_back(possible_token);
            possible_token.clear();
        }
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
