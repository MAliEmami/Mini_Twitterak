#ifndef SIGNUP_HPP
#define SIGNUP_HPP

#include <string>
#include <unordered_map>

class User 
{
public:
    User(std::string _userType);
    virtual ~User() = default;

    virtual void signUp() = 0;
    void saveData(std::unordered_map<std::string, std::string>& userData);

    std::string userType;
    std::string username;
    std::string password;
};

class PersonalUser : public User 
{
public:
    PersonalUser();
    void signUp() override;

private:
    std::string name;
    std::string number;
    std::string country;
    std::string birthday;
    std::string link;
    std::string biography;
};

class CompanyUser : public User 
{
public:
    CompanyUser();
    void signUp() override;

private:
    std::string companyName;
    std::string country;
    std::string link;
    std::string biography;
};

class AnonymousUser : public User 
{
public:
    AnonymousUser();
    void signUp() override;
};

#endif
