#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<stack>
#include<list>
#include<iostream>
#include<map>
#include<unordered_map>
#include<grid_define.h>
#include<worldmodel.h>
#include<algorithm>

void printGraph(const std::vector<std::vector<int>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        for(int j = 0; j < graph[i].size(); j++ )
        {
            if (graph[i][j] == 1)  //obstacle
                printf(" # ");
            else if(graph[i][j] == 2) //visited
                std::cout << "\033[1;31m v \033[0m";
            else if(graph[i][j] == 3) //path
                std::cout << "\033[1;34m @ \033[0m";
            else
                printf("   "); //empty
        }
        std::cout<<std::endl;
    }
    std::cout<<std::endl;
}

bool isIn(std::vector<GridLocation> visited, GridLocation elements)
{
    int k = 0;
    for(int i=0; i<visited.size(); i++)
    {
        if (elements == visited[i])
        {
            k++;
        }
    }
    if(k==0)
        return false;
    else
        return true;
}
std::vector<GridLocation> constructionPath(GridLocation startPoint, GridLocation targetPoint,
                                           std::map<GridLocation,GridLocation> pred)
{
    std::vector<GridLocation> path;

    GridLocation current = targetPoint;
    while (current != startPoint) {
        path.push_back(current);
        current = pred[current];
    }
    path.push_back(startPoint); // optional
    std::reverse(path.begin(), path.end());
    return path;
}
void DFS_search_updated(std::vector<std::vector<int>> graph,
                        GridLocation startPoint,  GridLocation targetPoint)
{

    std::stack<GridLocation> tovisit_Stack;
    std::vector<GridLocation> visited;
    std::map<GridLocation,GridLocation> pred;
    bool r = false;

    int NOOfvisited = 0;
    int lengthOfPath = 0;

    tovisit_Stack.push(startPoint);
    pred[startPoint] = startPoint;
    while(!tovisit_Stack.empty() && !r)
    {
        GridLocation s = tovisit_Stack.top();
        tovisit_Stack.pop();

        graph[s.x][s.y] = 2;
        NOOfvisited++;

        printGraph(graph);
        for(int i = 0; i<100000000; i++);
        if( (s.x == targetPoint.x - 1) && (s.y == targetPoint.y - 1))
        {
            r = true;
            pred[targetPoint] = s;
        }
        else
        {
            for(auto s_pren : neighboorLocation(s) )
            {
                if(s_pren.x < graph.size() && s_pren.y < graph[0].size())
                {
                    if (graph[s_pren.x][s_pren.y] != 1 && !isIn(visited, s_pren)&&
                            pred.find(s_pren) == pred.end())
                    {
                        tovisit_Stack.push(s_pren);
                        visited.push_back(s_pren);
                        pred[s_pren] = s;
                    }
                }
            }
        }
    }
    if(r)
    {
        std::vector<GridLocation> path;
        path = constructionPath(startPoint,  targetPoint, pred);
        lengthOfPath = path.size();

        for(int i = 0; i<path.size() - 1; i++)
        {
            graph[path[i].x][path[i].y] = 3;
        };
        printGraph(graph);
        printf("find path!\n");
        printf("num of visited: %d\n",NOOfvisited);
        printf("path length: %d\n", lengthOfPath);
        return;

    }
    else
    {
        printf("can not find path");
        printf("num of visited: %d\n",NOOfvisited);
        return;
    }
}


void BFS_search_updated(std::vector<std::vector<int>> graph,
                        GridLocation startPoint,  GridLocation targetPoint)
{
    std::queue<GridLocation> tovisit_Stack;
    std::vector<GridLocation> visited;
    std::map<GridLocation,GridLocation> pred;
    bool r = false;

    int NOOfvisited = 0;
    int lengthOfPath = 0;

    tovisit_Stack.push(startPoint);
    pred[startPoint] = startPoint;
    while(!tovisit_Stack.empty() && !r)
    {
        GridLocation s = tovisit_Stack.front();
        tovisit_Stack.pop();

        graph[s.x][s.y] = 2;
        NOOfvisited++;

        printGraph(graph);
        for(int i = 0; i<100000000; i++);
        if( (s.x == targetPoint.x - 1) && (s.y == targetPoint.y - 1))
        {
            r = true;
            pred[targetPoint] = s;
        }
        else
        {
            for(auto s_pren : neighboorLocation(s) )
            {
                if(s_pren.x < graph.size() && s_pren.y < graph[0].size())
                {
                    if (graph[s_pren.x][s_pren.y] != 1 && !isIn(visited, s_pren)&&
                            pred.find(s_pren) == pred.end())
                    {
                        tovisit_Stack.push(s_pren);
                        visited.push_back(s_pren);
                        pred[s_pren] = s;
                    }
                }
            }
        }
    }
    if(r)
    {
        std::vector<GridLocation> path;  //construct the path
        path = constructionPath(startPoint,  targetPoint, pred);
        lengthOfPath = path.size();
        for(int i = 0; i<path.size() - 1; i++)
        {
            graph[path[i].x][path[i].y] = 3;

        };
        printGraph(graph);
        printf("find path!\n");
        printf("num of visited: %d\n",NOOfvisited);
        printf("path length: %d\n", lengthOfPath);
        return;

    }
    else
    {
        printf("can not find path");
        printf("num of visited: %d\n",NOOfvisited);
        return;
    }
}



