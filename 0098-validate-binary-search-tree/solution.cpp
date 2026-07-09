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
    bool solve(TreeNode* root , long long  mini , long long maxi){
        if(root == NULL){
            return true ;
        }

        if(root->val > mini && root->val < maxi ){
            bool left = solve(root->left , mini , root->val);
            bool right = solve(root->right , root->val , maxi);

            return left && right ;
        }

        return false ;
    }
    // void inorder(TreeNode* root , vector<int>&ans){
    //     if(root == NULL){
    //         return ;
    //     }

    //     inorder(root->left , ans) ;
    //     ans.push_back(root->val) ;
    //     inorder(root->right , ans) ;

    // }
    bool isValidBST(TreeNode* root) {
        return solve(root ,  LONG_MIN , LONG_MAX) ;
        // vector<int>ans ;
        // inorder(root , ans) ;

        // for(int i=1 ; i<ans.size() ; i++){
        //     if(ans[i-1] < ans[i]){
        //         continue ;
        //     }
        //     else{
        //         return false ;
        //     }
        // }

        // return true ;
    }
};
