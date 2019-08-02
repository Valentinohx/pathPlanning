
#include<stdlib.h>
#include<vector>


class WorldModel
{
public:
    WorldModel(int _height, int _length, int _seedN, double _probability);
    WorldModel(int _height, int _length, double _probability);
    WorldModel(int _height, int _length, int _seedN);
    WorldModel(int _height, int _length);

   /* ~WorldModel(){
        delete worldDescription;
    }*/


    inline int Getheight()
    {
        return height;
    }

    inline int Getlength()
    {
        return length;
    }
    inline int Getprob()
    {
        return probability;
    }

    void WorldModelGenerator();
    void printWorld();

    inline bool accessble(int x, int y)
    {
        return !worldDescription[x][y];
    }

     std::vector<std::vector<int>> GetWorldMatrix(){
        return worldDescription;
    }

private:
    int height;
    int length;
    double probability;
    int seedN;
    std::vector <std::vector<int>> worldDescription;
};
