#include <fstream>
//#include <openssl/sha.h>
#include <cstring>
#include "User.hpp"

User* User::registerUser(char _username[], char _password[], char _email[])
{
    if(strlen(_username) > MAX_USERNAME_SIZE || strlen(_email) > MAX_EMAIL_SIZE)
    {
        return nullptr;
    }
    User* newUser = new User();
    strcpy(newUser->username, _username);
    //strcpy(newUser->passHash,SHA256(_password));
    strcpy(newUser->passHash, _password);
    strcpy(newUser->email,_email);
    std::ofstream fout;
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
    User* tmp = new User;
    bool flag = false;
    std::ifstream fin;
    fin.open("user.db",std::ios::binary);
    while(fin.read((char*)tmp, sizeof(User)))
    {
        //if(!strcmp(_username, tmp.username) && !strcmp(SHA256(_password), tmp.passHash))
        std::cout<<tmp->username<<" "<<tmp->passHash<<std::endl;
        std::cout<<_username << " " << _password<<std::endl;
        if(!strcmp(_username, tmp->username) && !strcmp(_password, tmp->passHash))
        {
            std::cout<<"TUKA"<<std::endl;
            flag = true;
            break;
        }
    }
    if(flag)
    {
        std::cout << tmp;

        return tmp;
    }
    else
    {
        return nullptr;
    }
}