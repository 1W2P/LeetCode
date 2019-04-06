/*
 * @lc app=leetcode id=646 lang=cpp
 *
 * [646] Maximum Length of Pair Chain
 *
 * https://leetcode.com/problems/maximum-length-of-pair-chain/description/
 *
 * algorithms
 * Medium (48.18%)
 * Total Accepted:    33.1K
 * Total Submissions: 68.8K
 * Testcase Example:  '[[1,2], [2,3], [3,4]]'
 *
 * 
 * You are given n pairs of numbers. In every pair, the first number is always
 * smaller than the second number.
 * 
 * 
 * 
 * Now, we define a pair (c, d) can follow another pair (a, b) if and only if b
 * < c. Chain of pairs can be formed in this fashion. 
 * 
 * 
 * 
 * Given a set of pairs, find the length longest chain which can be formed. You
 * needn't use up all the given pairs. You can select pairs in any order.
 * 
 * 
 * 
 * Example 1:
 * 
 * Input: [[1,2], [2,3], [3,4]]
 * Output: 2
 * Explanation: The longest chain is [1,2] -> [3,4]
 * 
 * 
 * 
 * Note:
 * 
 * The number of given pairs will be in the range [1, 1000].
 * 
 * 
 */
#include <vector>
#include <list>
#include <algorithm>

using namespace std;

class Solution
{
  public:
    static bool compare(vector<int> a, vector<int> b)
    {
        return a[1] < b[1];
    }
    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end(), compare);

        int chain = 1;
        int next = pairs[0][1];
        int pairSize = pairs.size();

        for (int i = 1; i < pairSize; i++)
        {
            if (next < pairs[i][0])
            {
                chain++;
                if (pairs[i][1] > next)
                    next = pairs[i][1];
            }
        }

        return chain;
    }
};
