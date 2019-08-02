#include"grid_define.h"
#include"searchingalgorithm.cpp"
#include<list>
#include<wait.h>
#include<unordered_map>
#include<utility>


int main()
{

    int x =25; int y =25;
    WorldModel myworld(x,y,0.3);
    myworld.WorldModelGenerator();
    myworld.printWorld();
    GridLocation startPoint{0,0};
    GridLocation targetPoint{x,y};
    DFS_search_updated(myworld.GetWorldMatrix(), startPoint, targetPoint);
    BFS_search_updated(myworld.GetWorldMatrix(), startPoint, targetPoint);
    return 0;
}
