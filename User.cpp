#include <fstream>
#include <openssl/sha.h>
#include <cstring>
#include "User.hpp"

User* User::registerUser(String& _username, String& _password, String& _email)
{
    User* newUser = new User();
    newUser->username = _username;
    unsigned char* hashtmp = new unsigned char[65];
    SHA256((const unsigned char*)_password.getData(),_password.Size(),hashtmp);
    char* h = (char*) hashtmp;
    newUser->passHash = h;
    std::cout<<newUser->passHash<<std::endl;
    newUser->email = _email;
    std::ofstream fout;
    fout.open("user.db",std::ios::app|std::ios::binary);
    if(fout)
    {
        fout.write((char*)newUser, sizeof(User));
    }
    fout.close();
    return newUser;
}
void readStringFromFile(String& container, std::ifstream in)
{
    char symbol=' ';
    while(symbol != '\0')
    {
        in.read(&symbol,sizeof(symbol));
        container.append(&symbol);
    }
}
User* User::loginUser(String _username, String _password)
{
    User* tmp = new User;
    bool flag = false;
    std::ifstream fin;
    fin.open("user.db",std::ios::binary);
    while(fin.read((char*)tmp, sizeof(User)))
    {
        
        std::cout<<tmp->username<<" "<<tmp->passHash<<std::endl;
        std::cout<<_username << " " << _password<<std::endl;
        //if(_username == tmp->username && !strcmp(_password, tmp->passHash))
        unsigned char* hashtmp = new unsigned char[65];
        SHA256((const unsigned char*)_password.getData(),_password.Size(),hashtmp);
        String hash;
        
        hash = (char*)*hashtmp;
        if(_username == tmp->username && hash == tmp->passHash)
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