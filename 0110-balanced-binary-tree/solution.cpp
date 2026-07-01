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
    // int height(TreeNode * root){
    //     if(root == NULL){
    //         return 0 ;
    //     }

    //     int left = height(root->left) ;
    //     int right = height(root->right) ;

    //     int ans = max(left , right) +1 ;
    //     return ans ;
    // }

    pair<bool , int>isbalance(TreeNode * root){
        if(root == NULL){
            return {true , 0} ;
        }

        pair<bool , int>left = isbalance(root->left);
        pair<bool , int>right = isbalance(root->right);

        bool opt1 = left.first ;
        bool opt2 = right.first ;

        bool diff = abs(left.second - right.second) <= 1;
        pair<bool , int>ans ;
        if(opt1 && opt2 && diff){
            ans.first = true ;
            ans.second= max(left.second , right.second) +  1;
        }
        else{
            ans.first = false ;
            ans.second= max(left.second , right.second) +  1;
        }

        return ans ;


    }
    bool isBalanced(TreeNode* root) {
        //TC O(N2) optimize krenge 
        // if(root == NULL){
        //     return true ;
        // }

        // bool left = isBalanced(root->left) ;
        // bool right = isBalanced(root->right) ;
        // bool ans = false ;
        // if(abs(height(root->left) - height(root->right)) <=1){
        //     ans = true ;
        // }

        // if(left && right && ans){
        //     return true ;
        // } 
        // else{
        //     return false ;
        // }

        return isbalance(root).first ;
        
    }
};
