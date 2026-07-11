/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // if(root == NULL){
        //     return NULL ;
        // }

        // if(root -> val < p->val  && root -> val < q-> val){//agr root ka data p and q dono se chota hai toh right subtree mai jaana hoga 
        //     return lowestCommonAncestor(root -> right , p , q) ;
        // }
        // if(root -> val > p->val  && root -> val > q-> val){//agr root ka data p and q dono se bda hai toh left subtree mai jaana hoga 
        //     return lowestCommonAncestor(root -> left , p , q) ;
        // }
        // else{//agr root ka data ek se bda and ek se chota hua toh yaani root hi lca hai 
        //     return root ;
        // }

        //above recursive call ko iterative bhi kr skte hai 

        while(root!= NULL){

            if(root -> val < p->val  && root -> val < q-> val){
                root = root -> right ;
            }

            else if(root -> val > p->val  && root -> val > q-> val){
                root = root -> left ;
            }

           else
            return root ;
            
        }

        return root ;
        

    }
};
