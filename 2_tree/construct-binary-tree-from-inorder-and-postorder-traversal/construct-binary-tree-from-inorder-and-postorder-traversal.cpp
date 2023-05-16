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

// https://www.youtube.com/watch?v=LgLRTaEMRVc&ab_channel=takeUforward
class Solution {
public:
    TreeNode* build(vector<int>& postorder, int pros, int proe, vector<int>& inorder, int inos, int inoe,map<int,int>& inMap)
    {
        if(pros>proe or inos>inoe)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(postorder[proe]);
         
        //find out where the root is in inorder traversal
        int inRoot=inMap[postorder[proe]];
        int numsLeft=inRoot-inos;

        root->left=build(postorder, pros, pros+numsLeft-1, inorder, inos, inRoot-1, inMap);
        root->right=build(postorder, pros+numsLeft, proe-1, inorder, inRoot+1,inoe, inMap);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int>inMap;

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        
        int n=postorder.size()-1;
        int m=inorder.size()-1;
        TreeNode* root=build(postorder, 0, n, inorder, 0, m, inMap);
        return root;
    }
};