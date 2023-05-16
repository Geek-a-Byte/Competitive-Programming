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
    
    bool valBST(TreeNode* node,long minVal, long maxVal){
     if(node==NULL)
     {
        return true;
     }
     cout<<node->val<<" "<<minVal<<" "<<maxVal<<endl;
     if(node->val<=minVal or node->val>=maxVal) return false;
     else 
     {
        return (valBST(node->left, minVal, node->val) && valBST(node->right, node->val, maxVal));
     }
}

    bool isValidBST(TreeNode* node) {
        return valBST(node, LONG_MIN, LONG_MAX);
    }
};