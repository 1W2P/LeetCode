/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> result;
        vector<int> tempResult;
        queue<pair<TreeNode*, int>> q;
        pair<TreeNode*, int> node;
        int level=0;
        
        if(root==NULL) return result;
        
        node = make_pair(root, 0);
        q.push(node);
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            if(node.second==level){
                tempResult.push_back(node.first->val);
            }else{
                level=node.second;
                result.push_back(tempResult);
                tempResult.clear();
                tempResult.push_back(node.first->val);
            }
            
            if(node.first->left!=NULL) {
                pair<TreeNode*, int> child = make_pair(node.first->left, node.second+1);
                q.push(child);
            }
            if(node.first->right!=NULL) {
                pair<TreeNode*, int> child = make_pair(node.first->right, node.second+1);
                q.push(child);
            }
        }
        result.push_back(tempResult);
        
        return result;
    }
};
