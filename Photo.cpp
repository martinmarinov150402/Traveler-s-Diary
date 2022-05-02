#include <iostream>
#include <fstream>
#include "Photo.hpp"

Photo::Photo(int _postId, char* _photoName)
{
    postId = _postId;
    photoName = photoName;
}
void Photo::savePhoto()
{
    std::ofstream out;
    out.open("photos.dat", std::ios::app|std::ios::binary);
    if(out)
    {
        out.write((char*)&postId, sizeof(postId));
        photoName.writeInFile(out);
    }
    out.close();
}