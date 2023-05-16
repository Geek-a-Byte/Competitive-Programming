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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        if(root==NULL)
        {
            return {};
        }
        
        queue<TreeNode*>q;
        vector<vector<int>>v;
        q.push(root);
        while(!q.empty())
        {
            vector<int>v2;
            int n=q.size();
            while(n--)
            {
                TreeNode* curr=q.front();
                q.pop();
                v2.push_back(curr->val);
                if(curr->left)
                {
                    q.push(curr->left);
                }
                if(curr->right)
                {
                    q.push(curr->right);
                }
            }
            v.push_back(v2);
        }
        return v;
    }
};