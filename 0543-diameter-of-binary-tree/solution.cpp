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

    pair<int , int>diameter(TreeNode* root){//diameter , height return kr rhe hai ab TC O(N) hai 
        if(root == NULL){
            return {0,0} ;
        }

        pair<int , int> left = diameter(root->left) ;
        pair<int , int> right = diameter(root->right) ;
        
        int opt1 = left.first ;
        int opt2 = right.first ;
        int opt3 = left.second + right.second   ;

        pair<int, int>ans ;
        ans.first = max(opt1 , max(opt2 , opt3)) ;
        ans.second = max(left.second , right.second) +1 ;

        return ans ;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        //TC O(N^2) 
        // if(root == NULL){
        //     return 0;
        // }

        // int opt1 = diameterOfBinaryTree(root->left) ;
        // int opt2 = diameterOfBinaryTree(root->right) ;
        // int opt3 = (height(root->left)+height(root->right)) ;//yha hum no of edges le rhe hai naaki no of nodes 


        // int ans = max(opt1 , max(opt2 , opt3))  ;

        // return ans ;

        return diameter(root).first ;
    }
};
