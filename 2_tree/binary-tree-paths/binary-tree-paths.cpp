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
    void paths(vector<string>&ans, TreeNode* root, string s)
    {
        s+=to_string(root->val);
        s+="->";
        if(!root->left and !root->right)
        {
            s=s.substr(0,s.length()-2);
            ans.push_back(s);
            return;
        }
        if(root->left)
        {
            paths(ans, root->left, s);
        }
        if(root->right)
        {
            paths(ans, root->right, s);
        }
        return;
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s="";
        vector<string>v;
        paths(v, root, s);
        return v;
    }
};