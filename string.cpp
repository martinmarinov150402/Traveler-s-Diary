#include "string.h"
#include <cstring>
#include <fstream>

const size_t DEFAULT_CAPACITY = 10;
String::~String()
{
    delete[] data;
}
String::String()
{
    capacity = DEFAULT_CAPACITY;
    size = 0;
    data = new char[capacity];
    data[0] = '\0';
}
void String::copy(String& other)
{
    size = other.size;
    capacity = other.capacity;
    data = new char[capacity];
    strcpy(data,other.data);
}
String::String(String& other)
{
    std::cout<<other<<std::endl;
    std::cout<<&other<<std::endl;
    size = other.size;
    capacity = other.capacity;
    data = new char[capacity];
    strcpy(data,other.data);
}
String& String::operator=(String& other)
{
    if(this != &other)
    {
        delete[] data;
        copy(other);
    }
    return *this;
}
String& String::operator=(char* other)
{
    size = strlen(other);
    capacity = size+1;
    delete[] data;
    data = new char[capacity];
    strcpy(data,other);
    return *this;
}
String& String::operator=(const char* other)
{
    size = strlen(other);
    capacity = size+1;
    delete[] data;
    data = new char[capacity];
    strcpy(data,other);
    return *this;
}
void String::readFromFile(std::ifstream& in)
{
    if(!in)
    {
        return;
    }
    size = 0;
    capacity = DEFAULT_CAPACITY;
    delete[] data;
    data = new char[capacity];
    char sym=' ';
    while(sym != '\0')
    {
        in.read(&sym,sizeof(sym));
        if(size + 1 > capacity)
        {
            char *tmp = data;
            capacity *= 2;
            data = new char[capacity];
            strcpy(data,tmp);
        }
        data[size++] = sym;
    }
}
void String::writeInFile(std::ofstream& out)
{
    if(!out)
    {
        return;
    }
    out.write(data,size);
    char term0 = '\0';
    out.write(&term0, sizeof(char));
}
String::String(char* other)
{
    *this = other;
}
size_t String::Size()
{
    return size;
}
void String::append(char* other)
{
    if(capacity < size + strlen(other))
    {
        capacity = capacity + strlen(other);
        char *tmp = data;
        data = new char[capacity];
        strcpy(data,tmp);
        delete[] tmp;
    }
    size = size + strlen(other);
    strcat(data,other);   
}
void String::append(String& other)
{
    append(other.data);
}
std::ostream& operator<<(std::ostream& out, String const& str)
{
    out<<str.data;
    return out;
}
bool String::operator==(String& other)
{
    bool flag = true;
    if(size == other.size)
    {
        for(int i = 0; i < size && flag; i++)
        {
            if(data[i] != other.data[i])
            {
                flag = false;
            }
        }
    }
    else
    {
        flag = false;
    }
    return flag;
}
const char* String::getData()
{
    return data;
}