/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int fun(TreeNode* root,bool& flag){
        if(!flag) return 0;
        if(root==NULL) return 0;

        int left = fun(root->left,flag);
        int right = fun(root->right,flag);
        flag = flag && abs(left-right) <= 1;
        return max(left,right)+1;

    }
    bool isBalanced(TreeNode* root) {
        bool flag = true;
        fun(root,flag);
        return flag;
    }
};
