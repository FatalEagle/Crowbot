#ifndef LEXXER_H_INCLUDED
#define LEXXER_H_INCLUDED

#include "basicresource.h"

class Lexxer
{
private:
    int current_token;
    std::vector<std::string> tokens;
public:
    void generateTokens(std::string raw);
    std::string getNextToken();
};

#endif // LEXXER_H_INCLUDED
