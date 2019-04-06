/*
 * @lc app=leetcode id=797 lang=cpp
 *
 * [797] All Paths From Source to Target
 *
 * https://leetcode.com/problems/all-paths-from-source-to-target/description/
 *
 * algorithms
 * Medium (69.80%)
 * Total Accepted:    24.9K
 * Total Submissions: 35.7K
 * Testcase Example:  '[[1,2],[3],[3],[]]'
 *
 * Given a directed, acyclic graph of N nodes.  Find all possible paths from
 * node 0 to node N-1, and return them in any order.
 * 
 * The graph is given as follows:  the nodes are 0, 1, ..., graph.length - 1.
 * graph[i] is a list of all nodes j for which the edge (i, j) exists.
 * 
 * 
 * Example:
 * Input: [[1,2], [3], [3], []] 
 * Output: [[0,1,3],[0,2,3]] 
 * Explanation: The graph looks like this:
 * 0--->1
 * |    |
 * v    v
 * 2--->3
 * There are two paths: 0 -> 1 -> 3 and 0 -> 2 -> 3.
 * 
 * 
 * Note:
 * 
 * 
 * The number of nodes in the graph will be in the range [2, 15].
 * You can print different paths in any order, but you should keep the order of
 * nodes inside one path.
 * 
 * 
 */
#include <vector>

using namespace std;

class Solution
{
  public:
    static void dfs(vector<vector<int>> &graph, int current, vector<int> &path, vector<vector<int>> &ans)
    {
        if (current == graph.size() - 1)
        {
            vector<int> end(path);
            ans.push_back(end);
            return;
        }
        for (int i = 0; i < graph[current].size(); i++)
        {
            path.push_back(graph[current][i]);
            dfs(graph, graph[current][i], path, ans);
            path.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        tmp.push_back(0);
        dfs(graph, 0, tmp, ans);
        return ans;
    }
};
