#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"

class Robot : public Entity
{
private:
    std::map<std::string, std::function<void()>> robotFunctions;
public:
    void addFunction(std::string function_name, std::function<void()> function_arg);
    void executeFunction(std::string function_name);
};

#endif // ROBOT_H_INCLUDED
