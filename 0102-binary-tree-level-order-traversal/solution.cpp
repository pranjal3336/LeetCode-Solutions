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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q ;
        vector<vector<int>>ans ;
        // 1. Base Case: Agar tree khali hai toh direct wapas jao
        if(root == NULL){
            return ans ;
        }
        q.push(root) ;
        q.push(NULL) ;//null btayga ki yha ek level khtm hua hai isliye ek level ke baad null push kr rhe hai 
         vector<int>temp ;

        while(!q.empty()){
            TreeNode* topnode = q.front() ;
            q.pop() ;
            
            if(topnode == NULL){
                // Ek level pura ho gaya, temp ko ans mein daalo
                ans.push_back(temp); 
                temp.clear(); // Agle level ke liye temp khali kar do
                if(!q.empty()){
                    q.push(NULL) ;
                }
            }
            else{
                // 2. Sirf current node ki value temp mein daalni hai
                temp.push_back(topnode->val);

                // Children ko queue mein daalo
                if(topnode->left != NULL){
                    q.push(topnode->left) ;
                }
                if(topnode->right != NULL){
                    q.push(topnode->right) ;
                }
            }
        }

        return ans ;
    }
};
