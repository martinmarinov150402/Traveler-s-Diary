class Photo
{
    private:
        int postId;
        char photoName[201];
    public:
        static void createPhoto(int _postId, char* _photoName);
};