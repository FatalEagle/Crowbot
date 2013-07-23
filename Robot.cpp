#include "resource.h"

void Robot::addFunction(std::string function_name, std::function<void()> function_arg)
{
    robotFunctions[function_name]=function_arg;
}

void Robot::executeFunction(std::string function_name)
{
    auto it=robotFunctions.find(function_name);
    if(it!=robotFunctions.end())
    {
        it->second();
    }
}
