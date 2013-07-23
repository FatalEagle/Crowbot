#ifndef ROBOT_H_INCLUDED
#define ROBOT_H_INCLUDED

#include "basicresource.h"
#include "Entity.h"

class Robot : public Entity
{
private:
    std::map<std::string, std::function<void()>> robotFunctions;
public:
};

#endif // ROBOT_H_INCLUDED
