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
    int findMaxSum(TreeNode* root, int& maxi)
    {
        if(root==NULL)
        {
            return 0;
        }
        int left_subtree_sum = max(0,findMaxSum(root->left, maxi));
        int right_subtree_sum = max(0,findMaxSum(root->right, maxi));
        int val=root->val;
        maxi=max(maxi, val+left_subtree_sum+right_subtree_sum);
        return val+max(left_subtree_sum, right_subtree_sum);
    }
    int maxPathSum(TreeNode* root) {
        int maxi=INT_MIN;
        int ans=findMaxSum(root, maxi);
        return maxi;
    }
};