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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return NULL ;
        }

        if(root ->val == key){//yha delete wale operation krenge mtlb uss node tk pahuch gye jisse delete krna hai 

            if(root->left ==NULL && root->right ==NULL){//if jis node ko delete krna hai  has no children 
                delete root ;
                return NULL ;
            }
            //if jis node ko delete krna hai  has left children 
            else if(root ->left != NULL && root->right ==NULL){
                TreeNode* temp = root->left ;
                delete root ;
                return temp ; 
            }
            //if jis node ko delete krna hai  has right children 
            else if(root ->left == NULL && root->right !=NULL){
                TreeNode* temp = root->right ;
                delete root ;
                return temp ; 
            }
            //if jis node ko delete krna hai  has both 2 children  
            else if(root ->left != NULL && root->right !=NULL){
                //hum left tree mai se max value se root ko repace kr rhe hai and then uss node ko delete kr rhe hai taaki bst ki property verify rhe 
                TreeNode* temp = root->left ;
                while(temp ->right != NULL){
                    temp = temp ->right ;
                }
                root->val = temp -> val ;
                root->left =  deleteNode(root->left , temp->val ) ;
                //return root ;yha nhi bhi likhu tb bhi chl jayga kyonki end mai likha hai maine line 58 mai 
            }
        }
        else{
            if(root->val > key){//agr key chota hai root se toh left mai dhoondhge 
                root ->left = deleteNode(root->left , key) ;
            }
            else{//vrna right mai search krenge 
                root->right = deleteNode(root->right , key) ;
            }
        }

        return root ;
    }
};
