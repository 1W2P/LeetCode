/*
 * @lc app=leetcode id=343 lang=cpp
 *
 * [343] Integer Break
 *
 * https://leetcode.com/problems/integer-break/description/
 *
 * algorithms
 * Medium (47.43%)
 * Total Accepted:    75.2K
 * Total Submissions: 158.6K
 * Testcase Example:  '2'
 *
 * Given a positive integer n, break it into the sum of at least two positive
 * integers and maximize the product of those integers. Return the maximum
 * product you can get.
 * 
 * Example 1:
 * 
 * 
 * 
 * Input: 2
 * Output: 1
 * Explanation: 2 = 1 + 1, 1 × 1 = 1.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 10
 * Output: 36
 * Explanation: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36.
 * 
 * Note: You may assume that n is not less than 2 and not larger than 58.
 * 
 * 
 */
#include <math.h>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
  public:
    int integerBreak(int n)
    {
        int curr = 1;
        int max = 0;
        while (n != curr)
        {
            int cal;
            if (curr + 1 == n)
            {
                cal = n - 1;
            }
            else
            {

                int count = n / curr;
                int remain = n % curr;
                int a = pow(curr, count - 1) * (curr + remain);
                int b = pow(curr, count) * remain;
                cal = a < b ? b : a;
            }
            if (cal > max)
                max = cal;
            curr++;
        }
        return max;
    }
};
