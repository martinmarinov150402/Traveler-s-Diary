#ifndef DEF_STR
#define DEF_STR

#include <iostream>

class String
{
    private:
        char* data;
        size_t size;
        size_t capacity;
        void copy(String& other);

    public:
        String();
        String& operator=(String& other);
        String& operator=(char* other);
        String& operator=(const char other[]);
        void readFromFile(std::ifstream& in);
        void writeInFile(std::ofstream& out);
        String(String& other);
        String(char* other);
        ~String();
        size_t Size();
        void append(char* other);
        void append(String& other);
        bool operator==(String& other);
        const char* getData();
    
    friend std::ostream& operator<<(std::ostream& out, String const& str);
};
#endif