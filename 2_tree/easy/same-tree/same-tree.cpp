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
    bool isSameTree(TreeNode* tree1, TreeNode* tree2) {
        if(tree1==NULL and tree2==NULL)
        {
            return 1;
        }
        else if(tree1 and tree2 and tree1->val==tree2->val)
        {
            int left_subtrees_same = isSameTree(tree1->left, tree2->left);
            int right_subtrees_same = isSameTree(tree1->right, tree2->right);
            return (left_subtrees_same && right_subtrees_same);
        }
        return 0;
    }
};