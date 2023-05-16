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
    TreeNode* build(vector<int>& preorder, int pres, int pree, vector<int>& inorder, int inos, int inoe,map<int,int>& inMap)
    {
        if(pres>pree or inos>inoe)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode(preorder[pres]);
        
        //find out where the root is in inorder traversal
        int inRoot=inMap[preorder[pres]];
        int numsLeft=inRoot-inos;

        // new preorder index will start from 1+curr root's index and end on the same length as numsLeft
        // for root's left we will take the array on leftside of root on inorder array.
        // so new inorder index will be same as it is and end on inRoot-1
        root->left=build(preorder, pres+1, pres+numsLeft, inorder, inos, inRoot-1, inMap);
        
        // for root's right we will take index after pres+numsLeft as prestart
        // and preend will be as it is
        // for inorder the start index will start from inRoot+1 and at same index
        root->right=build(preorder, pres+numsLeft+1, pree, inorder, inRoot+1,inoe, inMap);

        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;

        for(int i=0;i<inorder.size();i++)
        {
            inMap[inorder[i]]=i;
        }
        
        int n=preorder.size()-1;
        int m=inorder.size()-1;
        TreeNode* root=build(preorder, 0, n, inorder, 0, m, inMap);
        return root;
    }

};