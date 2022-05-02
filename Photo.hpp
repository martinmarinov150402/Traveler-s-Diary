#include "string.h"

class Photo
{
    private:
        int postId;
        String photoName;
    public:
        Photo(int _postId, char* _photoName);
        void savePhoto();
};