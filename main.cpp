#include "User.hpp"
#include <iostream>

int main()
{
    User* tmp = User::loginUser("martin","12345");
    std::cout << tmp;    

}   