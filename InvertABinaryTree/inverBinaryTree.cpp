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
    
    
    TreeNode* invertTree(TreeNode* root) {
        
        if (root == nullptr) return nullptr;
        
        queue<TreeNode*> q;
        
        q.push(root);
        
        
        while(!q.empty()){
            
            TreeNode* curr = new TreeNode();
            TreeNode* l = new TreeNode();
            TreeNode* r = new TreeNode();
            l = nullptr;
            r = nullptr;
            
            
            curr = q.front(); q.pop();                    
            if (curr->left){q.push(curr->left); l = curr->left;}
            if (curr->right){q.push(curr->right); r = curr->right;}
            
            curr->left = r;
            curr->right = l;
            
            
        }
        
        return root;
    }
};
