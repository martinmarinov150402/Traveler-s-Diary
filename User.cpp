#include <fstream>
#include <openssl/sha.h>
#include "User.hpp"

User* User::registerUser(char _username[], char _password[], char _email[])
{
    if(strlen(_username) > MAX_USERNAME_SIZE || strlen(_email > MAX_EMAIL_SIZE))
    {
        return nullptr;
    }
    User* newUser new User();
    strcpy(newUser->username, _username);
    strcpy(newUser->password,SHA256(_password));
    strcpy(newUser->email,_email);
    ofstream fout;
    fout.open("user.db",std::ios::app|std::ios::binary);
    if(fout)
    {
        fout.write((char*)newUser, sizeof(User));
    }
    fout.close();
    return newUser;
}
User* User::loginUser(char _username[], char _password[])
{
    User tmp;
    bool flag = false;
    ifstream fin;
    fin.open("user.db",std::ios::binary);
    while(fin.read((char*)&tmp, sizeof(User)))
    {
        if(!strcmp(_username, tmp.username) && !strcmp(SHA1(_password), tmp.passHash))
        {
            flag = true;
            break;
        }
    }
    if(flag)
    {
        return &tmp;
    }
    else
    {
        return nullptr;
    }
}