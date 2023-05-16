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
   
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root)
        {
            return {};
        }

        queue<TreeNode*>q;
        q.push(root);
    
        bool left_to_right=true;

        vector<vector<int>>v2;
        vector<int>v;

        v.push_back(root->val);
        v2.push_back(v);

        while(!q.empty())
        {
            v.clear();
            int nc=q.size(); //no of nodes in the current lvl
            while(nc--)
            {
                TreeNode* parent=q.front();
                q.pop();
                if(parent->left)
                {
                    TreeNode* child=parent->left;
                    v.push_back(child->val);
                    q.push(child);
                }
                if(parent->right)
                {
                    TreeNode* child=parent->right;
                    v.push_back(child->val);
                    q.push(child);
                }
            }
            
            left_to_right=!(left_to_right);
            if(left_to_right==false)
            {
                reverse(v.begin(),v.end());
            }
            if(v.size()) v2.push_back(v);
        }
        return v2;
    }
};