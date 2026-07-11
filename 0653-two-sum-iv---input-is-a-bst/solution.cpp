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
    void solve(TreeNode* root , vector<int>&ans){
        if(root == NULL){
            return ;
        }

        solve(root -> left , ans) ;
        ans.push_back(root->val) ;
        solve(root->right , ans) ;

    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> ans ;
        solve(root , ans) ;

        //now ab inorder pr two pointer approach lga rhe hai hume pta hai bst ka inorder sorted hota hai 
        int i =0 ; 
        int j = ans.size() -1 ;//last index of ans 

        while(i<j){
            if(ans[i]+ ans[j] == k){
                return true ;
            }
            if(ans[i]+ ans[j] > k){//sum bda aa gya yaani km krenge sum ko j ko peeche laakr 
                j--;
            }else{//sum k yaani target se chota hai toh sum bda krne ke liye i++ krenge 
                i++ ;
            }
        }

        return false ;//true return nhi hua toh mtlb pair nhi hai false return krenge 
    }
};
