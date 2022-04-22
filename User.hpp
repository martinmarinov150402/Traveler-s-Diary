#ifndef USER_HPP
#define USER_HPP

const size_t MAX_USERNAME_SIZE = 100;
const size_t MAX_EMAIL_SIZE = 255;

class User
{
    private:
        char username[MAX_USERNAME_SIZE + 1];
        char passHash[65];
        char email[MAX_EMAIL_SIZE + 1];
    public:
        static User* registerUser(char _username[], char _password[], char _email[]);
        static User* loginUser(char _username[], char _password[]);


};
#endif