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
    int solve(TreeNode* root , int &maxSum){
        if(root == NULL){
            return 0 ;
        }

        int l = solve(root->left , maxSum) ;
        int r = solve(root->right , maxSum) ;

        // CASE 1: Path current node se hote hue ek 'U-Turn' le raha hai (Left -> Root -> Right).
        // Isko hum answer (maxSum) me consider kar sakte hain, par apne parent ko ye return nahi kar sakte 
        // kyunki fir path fork ho jayega (Y-shape) jo allowed nahi hai.
        int neech_mil_gaya = l + r + root->val ;// case 1 

        // CASE 2: Straight path ban raha hai (Ya toh Left->Root ya Right->Root).
        // Isme se max branch uthao, kyunki ye apne parent ke sath jud kar aur bada path bana sakta hai.
        int left_ya_right = max(l, r) + root->val ;//case 2
        // CASE 3: Agar left aur right dono branches negative result de rahi hain (nuksaan ho raha hai),
        // toh unko ignore maaro aur current node se hi fresh path shuru karo.
        int sirf_root = root->val ;//case 3
        // Ab tak ka sabse best answer inn teeno cases me se (ya purane maxSum me se) koi ek hoga.
        // Isliye yahan global maxSum ko update kar diya.
        maxSum = max({maxSum ,neech_mil_gaya , left_ya_right ,  sirf_root}) ;//max of all lenge 
        // PARENT KO RETURN KYA KAREIN?
        // Parent node ko sirf ek continuous straight line chahiye. 
        // Toh ya toh 'left_ya_right' bhejo, ya fir agar dono bekaar the toh 'sirf_root' bhej do
        return max(left_ya_right , sirf_root ) ;

    }
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN ;
        solve(root , maxSum) ;
        return maxSum ;

    }
};
