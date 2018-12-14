/*
https://leetcode.com/problems/symmetric-tree/submissions/
*/

#include <iostream>
using namespace std;

 struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if((left == NULL) && (right == NULL)){
            return true;
        }
        else if((left == NULL && right != NULL) || (left != NULL && right == NULL)) {
            return false;
        }
        else {
            if(left -> val != right -> val) {
            return false;
        }
            return isSymmetric(left -> left, right -> right) && isSymmetric(left -> right, right -> left);
        }
        return true;
    }
    
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) {
            return true;
        }
        else return isSymmetric(root -> left, root -> right);
    }
};
