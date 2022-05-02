#include "User.hpp"
#include "string.h"
class Post
{
    private:
        int id;
        int grade;
        String authorName;
        String dateStart;
        String dateEnd;
        String comment;

    public:
        void writePostInFile(std::ofstream& out);
        
};