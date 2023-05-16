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
    int isSymm(TreeNode* root1, TreeNode* root2){
        
        if(root1==NULL and root2==NULL)
        {
            return 1;
        }
        else if(root1 and root2 and root1->val==root2->val)
        {   
            int ll_mirror=isSymm(root1->left, root2->right);
            int rr_mirror=isSymm(root1->right, root2->left);
            return (ll_mirror && rr_mirror);
        }
        return 0;

    }   
    bool isSymmetric(TreeNode* root) {
        return isSymm(root, root);
    }
};