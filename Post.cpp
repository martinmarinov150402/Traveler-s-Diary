#include "Post.hpp"
#include "string.h"
#include <fstream>

void Post::writePostInFile(std::ofstream& out)
{
    if(out)
    {
        out.write((char*)&id, sizeof(id));
        out.write((char*)&grade, sizeof(grade));
        authorName.writeInFile(out);
        dateStart.writeInFile(out);
        dateEnd.writeInFile(out);
        comment.writeInFile(out);
    }
    
}