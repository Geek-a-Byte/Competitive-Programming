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
    int maxDepth(TreeNode* node, int& d)
    {
        if (node == NULL)
            return 0;
        else {
            int lDepth = maxDepth(node->left, d);
            int rDepth = maxDepth(node->right, d);
            d=max(d, lDepth + rDepth);
            return max(lDepth, rDepth)+1;
        }
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL)
        {
            return 0;
        }
        int d=0;
        int ans=maxDepth(root, d);
        return d;      
    }
};