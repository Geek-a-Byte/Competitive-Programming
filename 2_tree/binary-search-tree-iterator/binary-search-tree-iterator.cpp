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
class BSTIterator {
public:
    queue<int>q;
    void inOrder(TreeNode* node)
    {
        if (node == NULL)
            return;
    
        inOrder(node->left);
        q.push(node->val);
        inOrder(node->right);
    }

    BSTIterator(TreeNode* root) {
       inOrder(root);
    }
    
    int next() {
       int top=q.front();
       q.pop();
       return top;
    }
    
    bool hasNext() {
       return !q.empty(); 
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */