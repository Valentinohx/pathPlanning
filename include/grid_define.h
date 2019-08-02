#ifndef GRID_DEFINE_H
#define GRID_DEFINE_H
#include<stdlib.h>
#include<stdio.h>
#include<vector>
#include <tuple>
struct GridLocation {
    int x, y;
};

bool operator == (GridLocation a, GridLocation b) {
    return a.x == b.x && a.y == b.y;
}

bool operator != (GridLocation a, GridLocation b) {
    return !(a == b);
}

GridLocation operator + (GridLocation a, GridLocation b) {
    return { a.x+b.x , a.y+b.y };
}

bool operator < (GridLocation a, GridLocation b) {
    return std::tie(a.x, a.y) < std::tie(b.x, b.y);
}

const std::vector<GridLocation> DIRS =
{GridLocation{1, 0}, GridLocation{0, -1}, GridLocation{-1, 0}, GridLocation{0, 1}};


std::vector <GridLocation> neighboorLocation(GridLocation current_point)
{
    std::vector <GridLocation> neighboor;
    for (auto x : DIRS)
    {
        if((current_point + x).x >= 0 && (current_point + x).y  >= 0)
        {
            neighboor.push_back( current_point + x);
        }
    }
    return neighboor;
}

#endif // GRID_DEFINE_H

