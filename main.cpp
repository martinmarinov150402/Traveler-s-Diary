#include "User.hpp"
#include "string.h"
#include <iostream>
#include <fstream>
#include <cstring>

void readStringFromFile(String& container, std::ifstream& in)
{
    char symbol=' ';
    int c=0;
    while(symbol != '\0' && c<14)
    {
        c++; 
        
        in.read(&symbol,sizeof(symbol));
        std::cout<<symbol<<std::endl;
        container.append(&symbol);
    }
}
int main()
{
    String a,c;
    a = "test read from file";
    std::ofstream out;
    out.open("test.dat",std::ios::binary);
    a.writeInFile(out);
    out.close();
    std::ifstream testStream;
    testStream.open("test.dat", std::ios::binary);
    c.readFromFile(testStream);
    testStream.close();
    std::cout<<c<<std::endl;

    String b(a);
    String uname, password,email;
    uname = "martin";
    password = "12345";
    email = "martinmarinov150402@gmail.com";
    User* tmp = User::loginUser(uname,password);
    //User::registerUser(uname,password,email);
    std::cout << tmp;    

}   