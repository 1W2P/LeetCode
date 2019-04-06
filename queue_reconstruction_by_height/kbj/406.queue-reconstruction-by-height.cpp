/*
 * @lc app=leetcode id=406 lang=cpp
 *
 * [406] Queue Reconstruction by Height
 *
 * https://leetcode.com/problems/queue-reconstruction-by-height/description/
 *
 * algorithms
 * Medium (59.27%)
 * Total Accepted:    74.4K
 * Total Submissions: 125.5K
 * Testcase Example:  '[[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]'
 *
 * Suppose you have a random list of people standing in a queue. Each person is
 * described by a pair of integers (h, k), where h is the height of the person
 * and k is the number of people in front of this person who have a height
 * greater than or equal to h. Write an algorithm to reconstruct the queue.
 * 
 * 
 * Note:
 * The number of people is less than 1,100.
 * 
 * 
 * 
 * 
 * Example
 * 
 * Input:
 * [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
 * 
 * Output:
 * [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
 * 
 * 
 */
#include <vector>
#include <algorithm>
#include <list>
#include <iostream>

using namespace std;

class Solution
{
  public:
    static bool comp(pair<int, int> a, pair<int, int> b)
    {
        if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return a.first > b.first;
    }
    static void insert(list<pair<int, int>> &li, pair<int, int> p)
    {
        int count = 0;
        for (auto i = li.begin(); i != li.end(); i++)
        {
            if (i->first >= p.first)
                count++;
            if (p.second < count)
            {
                li.insert(i, p);
                return;
            }
            if (p.second == count)
            {
                i++;
                li.insert(i, p);
                return;
            }
        }
    }
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>> &people)
    {
        list<pair<int, int>> li;

        sort(people.begin(), people.end(), comp);

        for (auto p : people)
        {
            if (li.empty())
            {
                li.push_back(p);
            }
            else
            {
                insert(li, p);
            }
        }
        vector<pair<int, int>> ans;

        for (auto node : li)
        {
            ans.push_back(node);
        }
        return ans;
    }
};
