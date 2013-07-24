#include "resource.h"

#define SHOW_TOKENS

std::function<void()> Compiler::compile(Lexxer lexxer, Robot *robot)
{
    if(lexxer.getNextToken()=="__BEGIN")
    {
#ifdef SHOW_TOKENS
        printf("<Token: [__BEGIN]>\n");
#endif
        std::vector<std::function<void()>> lines;
        std::string tok;
        while(tok!="__END")
        {
            tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
            printf("<Token: [%s]>\n", tok.c_str());
#endif
            if(tok=="__FUNC")
            {
                tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
                printf("<Function Token: [%s]>\n", tok.c_str());
#endif
                lines.push_back([robot, tok]()
                                {
                                    robot->executeFunction(tok);
                                }
                                );
            }
            else if(tok=="output")
            {
                tok=lexxer.getNextToken();
#ifdef SHOW_TOKENS
                printf("<Output Token: [%s]>\n", tok.c_str());
#endif
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
