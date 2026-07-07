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
    int widthOfBinaryTree(TreeNode* root) {
        long long ans = 0 ;
        if(root == NULL){
            return ans ;
        }
        queue<pair<TreeNode* , long long>>q ;// Queue store karegi: {Current Node, Uss node ka Index}
        q.push({root , 0}) ;
        while(!q.empty()){
            int s = q.size() ;

            // TRICK: Level ke pehle node ka index nikal lo taaki aage minus karke overflow bacha sakein
            long long mini = q.front().second ;
            long long  first , last ;
            for(int i=0 ; i<s ; i++){
                // Normalize index to avoid Signed Integer Overflow
                long long curr_id = q.front().second - mini ;
                TreeNode* front = q.front().first ;
                q.pop() ;
                // Level ka sabse pehla node
                if(i==0){
                    first = curr_id ;
                }
                // Level ka sabse aakhiri node
                if(i == s-1){
                    last = curr_id ;
                }

                // 0-based indexing: Left child hamesha (curr_id * 2 + 1) hoga
                if(front->left){
                    q.push({front->left , curr_id*2+1}) ;
                }
                // 0-based indexing: Right child hamesha (curr_id * 2 + 2) hoga
                if(front->right){
                    q.push({front->right , curr_id*2+2}) ;
                }
            }
            // Width = (Aakhiri Node ka index - Pehle Node ka index + 1)
            ans = max(ans , last-first + 1) ;
        }

        return ans ;
    }
};
