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
    int maxDepth(TreeNode* node)
    {
        if (node == NULL)
            return 0;
        else {
            int lDepth = maxDepth(node->left);
            if(lDepth==-1) return -1;
            int rDepth = maxDepth(node->right);
            if(rDepth == -1) return -1;
            if(abs(lDepth-rDepth)>1) return -1;
            return max(lDepth, rDepth)+1;
        }
    }
    bool isBalanced(TreeNode* root) {
         if(maxDepth(root)==-1)
         {
             return false;
         }
         return true;
    }
};