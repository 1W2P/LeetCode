/*
 * @lc app=leetcode id=221 lang=cpp
 *
 * [221] Maximal Square
 *
 * https://leetcode.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (32.42%)
 * Total Accepted:    121.3K
 * Total Submissions: 374K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest square
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input: 
 * 
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 * 
 * Output: 4
 * 
 */

#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution
{
public:
  int maximalSquare(vector<vector<char>> &matrix)
  {
    int height = matrix.size();
    if (height == 0)
      return 0;

    int width = matrix[0].size();

    int ans = 0;

    vector<vector<int>> memo(height);

    for (int i = 0; i < height; i++)
    {
      memo[i] = vector<int>(width, 0);
    }

    for (int i = 0; i < height; i++)
    {
      for (int j = 0; j < width; j++)
      {
        if (i == 0 || j == 0)
        {
          memo[i][j] = matrix[i][j] == '1' ? 1 : 0;
        }
        else
        {
          int cross = memo[i - 1][j - 1];
          int top = memo[i - 1][j];
          int left = memo[i][j - 1];
          if (matrix[i][j] == '1')
            memo[i][j] = min(cross, min(top, left)) + 1;
        }
        if (memo[i][j] > ans)
          ans = memo[i][j];
      }
    }

    return ans * ans;
  }
};
