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
    vector<int>ans;
    vector<int> preorderTraversal(TreeNode* root) {
        // if the current node is empty
        if (root == nullptr) {
            return ans;
        }
    
        ans.push_back(root->val);
    
        // Traverse the left subtree
        ans = preorderTraversal(root->left);

    
        // Traverse the right subtree
        ans = preorderTraversal(root->right);
        
        return ans;
    }
};