#include "resource.h"

std::function<void()> Compiler::compile(Lexxer lexxer)
{
    if(lexxer.getNextToken()=="__BEGIN")
    {
        std::vector<std::function<void()>> lines;
        std::string tok;
        while(tok!="__END")
        {
            tok=lexxer.getNextToken();
            if(tok=="output")
            {
                tok=lexxer.getNextToken();
                lines.push_back([tok]()
                                {
                                    std::cout<<tok;
                                }
                                );
            }
        }
        return [lines]()
                        {
                            for(auto it : lines)
                            {
                                it();
                            }
                        };
    }
    return [](){};
}
