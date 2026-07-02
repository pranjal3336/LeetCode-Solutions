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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int  , map<int , vector<int>>>mp ;//first int horizontal distance bta rha hai and second int level bta rha hai and jo vector hai voh nodes store krega 
        queue<pair<TreeNode* , pair<int , int>>>q ; //phla int  horizontal  distance and second int level bta rha hai 
        q.push({root , {0 ,0}}) ;
        vector<vector<int>>ans ;
        while(!q.empty()){
            pair<TreeNode* , pair<int , int>> top = q.front() ;
            q.pop() ;

            TreeNode* frontnode = top.first ;
            int hd = top.second.first ;
            int lvl = top.second.second ;

            mp[hd][lvl].push_back(frontnode->val) ;

            if(frontnode->left){
                q.push({frontnode->left , {hd-1 , lvl+1}}) ;
            }

            if(frontnode->right){
                q.push({frontnode->right , {hd+1 , lvl+1}}) ;
            }
        }

        for(auto i: mp){
            vector<int>temp ;
            for(auto j: i.second){
                sort(j.second.begin(), j.second.end());//humne specific level ke nodes ko sort kra hai 
                for(auto k:j.second){
                    temp.push_back(k);
                }
            }
            ans.push_back(temp);
        }

        return ans ;
    }
};
