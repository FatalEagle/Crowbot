#include "resource.h"

std::string intToStr(int _int)
{
    std::stringstream _ss;
    _ss<<_int;
    std::string _str;
    _ss>>_str;
    return _str;
}

int strToInt(std::string _str)
{
    std::stringstream _ss(_str);
    int _int;
    _ss>>_int;
    return _int;
}

std::string leadZero(std::string str, unsigned int zeroes)
{
    while(str.length()<zeroes)
    {
        str="0"+str;
    }
    return str;
}
