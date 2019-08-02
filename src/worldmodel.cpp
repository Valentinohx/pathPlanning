#include<vector>
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<time.h>
//#include<GL/glew.h>
#include<stack>
#include<queue>
#include <set>
#include <tuple>

#include<worldmodel.h>


WorldModel::WorldModel(int _height, int _length, int _seedN, double _probability)
{
    height = _height;
    length = _length;
    seedN = _seedN;

    if( _probability >= 0 && _probability <=1 )
    probability = _probability;
    else
    {
        printf("invalid input of probility: %f, default value used", _probability);
        probability = 0.5;
    }
}

WorldModel::WorldModel(int _height, int _length, double _probability)
{

    height = _height;
    length = _length;

    seedN = time(NULL);

    if( _probability >= 0 && _probability <=1 )
    probability = _probability;
    else
    {
        printf("invalid input of probility: %f, default value used", _probability);
        probability = 0.5;
    }
}

WorldModel::WorldModel(int _height, int _length)
{
    height = _height;
    length = _length;
    probability = 0.5;  //if not provided, default value;
    seedN = time(NULL);
}

WorldModel::WorldModel(int _height, int _length, int _seedN)
{
    height = _height;
    length = _length;
    probability = 0.5;  //if not provided, default value
    seedN = _seedN;
}

void WorldModel::WorldModelGenerator()
{
    std::vector<int> lines(length,0);
    for(int k = 0; k < height; k++)
    {
        worldDescription.push_back(lines);
    }
    printf("seed: %d\n", seedN);
    srand (seedN);
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < length; j++ )
        {
            if(i == 0 && j == 0)
                worldDescription[i][j] = 0;
            else if ((i == height - 1) && (j = length - 1))
                worldDescription[i][j] = 0;
            else
            worldDescription[i][j] = (rand() % 100) > probability*100? 0:1;
        }
    }
}

void WorldModel::printWorld()
{
    for (int i = 0; i < height; i++)
    {
        for(int j = 0; j < length; j++ )
        {
            if (worldDescription[i][j] == 1)
            printf(" x ");
            else if(worldDescription[i][j] == 2)
                printf(" p ");
            else
                printf(" 0 ");
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}


