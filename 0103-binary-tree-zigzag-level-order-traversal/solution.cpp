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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        // Base case: Agar tree khali hai toh empty result return kardo
        if(root == NULL){
            return result;
        }
        
        // Standard BFS (Level Order) ke liye queue
        queue<TreeNode*> q;
        q.push(root);

        // Ye flag batayega ki current level mein left-to-right jana hai ya right-to-left
        bool lefttoright = true; 
        
        while(!q.empty()){
            // Current level mein total kitne nodes hain
            int size = q.size();
            
            // Is level ke elements store karne ke liye temporary array
            // Size pehle se de diya taaki specific index pe daal sakein (reverse ke liye)
            vector<int> temp(size);

            // Sirf current level ke nodes ko process karo
            for(int i = 0; i < size; i++){
                TreeNode* frontNode = q.front();
                q.pop();

                // MAIN LOGIC: 
                // Agar left-to-right hai toh shuru se daalo (i)
                // Agar right-to-left hai toh peeche se daalo (size - i - 1)
                int index = lefttoright ? i : size - i - 1;
                temp[index] = frontNode->val;

                // Agle level ke liye left aur right bacchon ko queue mein daalo
                if(frontNode->left){
                    q.push(frontNode->left);
                }
                if(frontNode->right){
                    q.push(frontNode->right);
                }
            }
            
            // Ek level poora hone ke baad direction flip kardo agle level ke liye
            lefttoright = !lefttoright;
            
            // Current level ke array ko final answer mein push kardo
            result.push_back(temp);
        }

        return result;
    }
};
