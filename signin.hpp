#ifndef SIGNIN_HPP
#define SIGNIN_HPP

#include <string>
#include <unordered_map>

class SignIn 
{
public:
    static bool login(const std::unordered_map<std::string, std::string>& userData);
};

#endif // SIGNIN_HPP
