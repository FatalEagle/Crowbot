#ifndef COMPILER_H_INCLUDED
#define COMPILER_H_INCLUDED

#include "basicresource.h"

class Lexxer;
class Robot;

class Compiler
{
private:
public:
    std::function<void()> compile(Lexxer lexxer, Robot *robot);
};

#endif // COMPILER_H_INCLUDED
