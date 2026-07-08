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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root==NULL){//yeh 2 kaam kr rhi hai agr root null hui yaani tree nhi hai tb null do vrna search krte hue bahr nikl gye tb null do 
            return NULL ;
        }

        if(root ->val == val){
            return root ;
        }

        if(root->val > val){
            return searchBST(root->left , val) ;
        }

        else{
            return searchBST(root->right , val) ;
        }

    }
};
