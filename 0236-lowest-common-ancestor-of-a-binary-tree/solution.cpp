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
        //Note for eg 2 : Agar p, q ka ancestor hai, toh yahi se early return ho jayega! yaani agr koi node kisi dusre ka ancestor hi hai toh toh jo ancestor yaani jo sabse phle mil gya vhi answer hoga neeche jaakr durse node ke liy check krne ki need nhi hai 
        
        // Base case 1: Tree ke end tak pahunch gaye, kuch nahi mila
        if(root == NULL){
            return NULL; 
        }
        
        // Base case 2: Agar p ya q yahi node hai, toh seedha yahi return karo (Early return)
        if(root->val == p->val || root->val == q->val){
            return root; 
        }
        
        // Recursion: Left aur Right subtrees mein p aur q ko dhundho
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // Case 1: Ek node left se mila, doosra right se. Matlab yehi current node LCA hai!
        if(left != NULL && right != NULL){
            return root; 
        }
        // Case 2: Left mein kuch nahi mila, jo bhi hai right mein hai (LCA right subtree mein hai)
        else if(left == NULL && right != NULL){
            return right; 
        }
        // Case 3: Right mein kuch nahi mila, jo bhi hai left mein hai (LCA left subtree mein hai)
        else if(left != NULL && right == NULL){
            return left; 
        }
        // Case 4: Dono taraf kuch nahi mila
        else{
            return NULL; 
        }
    }
};
