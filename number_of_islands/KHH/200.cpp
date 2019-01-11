//
//  200.cpp
//  Algorithm_Cpp
//
//  Created by 김혜현 on 11/01/2019.
//  Copyright © 2019 Hyen. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

const char LAND = '1';
const char VISIT = '2';

using namespace std;

class Solution {
private:
    int X;
    int Y;
public:
    int numIslands(vector<vector<char>>& grid)
    {
        int result = 0;
        
        if(grid.empty()) return 0;
        
        X = (int)grid.size();
        Y = (int)grid[0].size();
        
        for(int i = 0; i < X; ++i)
        {
            for(int j = 0; j < Y; ++j)
            {
                if(grid[i][j] == LAND)
                {
                    ++result;
                    countLand(i,j,grid);
                }
            }
        }
        return result;
    }
    
    void countLand(int x, int y, vector<vector<char>>& grid)
    {
         if (x < 0 || y < 0 || x >= X || y >= Y) return;
         else if(grid[x][y] == LAND)
         {
             grid[x][y] = VISIT;
             countLand(x+1, y, grid);
             countLand(x-1, y, grid);
             countLand(x, y+1, grid);
             countLand(x, y-1, grid);
         }
     }
};


int main()
{
    Solution sol;
//    vector<vector<char>> testCase ={{'1','1','1','1','0'},
//                                    {'1','1','0','1','0'},
//                                    {'1','1','0','0','0'},
//                                    {'0','0','0','0','0'}};
    vector<vector<char>> testCase ={{'1','0','1','1','0','1','1'}};
    cout << sol.numIslands(testCase) << endl;
    return 0;
}
