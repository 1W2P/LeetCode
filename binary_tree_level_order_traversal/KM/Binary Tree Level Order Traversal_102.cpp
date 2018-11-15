#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution 
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) 
	{
		vector<vector<int>> result;
		queue<TreeNode*> tree_queue;

		if (root == NULL)
			return result;

		tree_queue.push(root);

		while (!tree_queue.empty())
		{
			vector<int> level_vector;
			queue<TreeNode*> next_queue;

			do
			{
				auto node = tree_queue.front();
				tree_queue.pop();

				level_vector.push_back(node->val);

				if (node->left != NULL)
					next_queue.push(node->left);
				if (node->right != NULL)
					next_queue.push(node->right);
			} while (!tree_queue.empty());

			tree_queue = next_queue;
			result.push_back(level_vector);
		}

		return result;
	}
};

/*
 * [3,9,20,null,null,15,7]
			3
		   / \
		  9  20
			/  \
		   15   7
 */

int main(void)
{
	TreeNode* node0 = new TreeNode(3);
	TreeNode* node1 = new TreeNode(9);
	TreeNode* node2 = new TreeNode(20);
	TreeNode* node3 = new TreeNode(15);
	TreeNode* node4 = new TreeNode(7);
	vector<vector<int>> result;

	node0->left = node1;
	node0->right = node2;

	node2->left = node3;
	node2->right = node4;

	result = Solution().levelOrder(node0);

	for (auto i = 0; i < result.size(); ++i)
	{
		for (auto j = 0; j < result[i].size(); ++j)
		{
			cout << result[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}