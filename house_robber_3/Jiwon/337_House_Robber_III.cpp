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
    
    map<TreeNode*, int> cache;
    
    int rob(TreeNode* root) {
        
        if(root==NULL) return 0;
        
        int rootSum=root->val, ignoreRootsum=0; 
        
        int& res = cache[root];
        if(res!=NULL) return res;
        
        if(root->left!=NULL) {
            rootSum = rootSum + rob(root->left->left) + rob(root->left->right);
            ignoreRootsum = ignoreRootsum + rob(root->left);
        }
        if(root->right!=NULL){
            rootSum = rootSum + rob(root->right->left) + rob(root->right->right);
            ignoreRootsum = ignoreRootsum + rob(root->right);
        }
        
        if(rootSum>ignoreRootsum) return res = rootSum;
        else return res = ignoreRootsum;
    }
};
