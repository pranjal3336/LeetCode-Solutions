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
    void mapping(vector<int>&inorder ,map<int , int>&mp ){
        for(int i=0 ; i<inorder.size() ; i++){
            mp[inorder[i]] = i ;
        }
    }

    TreeNode* solve(vector<int>&inorder , vector<int>& preorder , int &index , int startin , int endin , map<int , int> &mp){
        
        if(index >= preorder.size() || startin > endin){
            return NULL ;
        }
        int element = preorder[index] ;
        index++ ;
        TreeNode* root = new TreeNode(element) ;

        int position = mp[element] ;

        root->left = solve(inorder , preorder , index , startin , position-1 , mp) ;

        root->right = solve(inorder , preorder , index , position+1 , endin , mp) ;

        return root ;

    }

    TreeNode* solve1(vector<int>& preorder , int mini , int maxi , int &index){
        if(index >= preorder.size()){//index preorder ke size se bahr nikl gya 
            return NULL ;
        }

        if(preorder[index] <mini || preorder[index]>maxi){//agr range se bahr hai current element of preorder vector
            return NULL ;
        }

        //yha aaye hai mtlb range mai hai 
        TreeNode* root = new TreeNode(preorder[index]) ;
        index++ ;

        root ->left = solve1(preorder , mini , root->val , index) ;
        root ->right = solve1(preorder ,root->val , maxi , index) ;

        return root ;

    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //method 1 using inorder and preorder yha humne preorder ko sort krke inorder nikala hai phir binary tree wala hi concept use kr liya 
        // vector<int>inorder  ;
        // int preorderindex =0 ;
        // for(int i=0 ; i<preorder.size() ; i++){
        //     inorder.push_back(preorder[i]) ;
        // }

        // sort(inorder.begin() , inorder.end()) ;

        // map<int , int> mp ;
        // mapping(inorder , mp) ;

        // return solve(inorder , preorder , preorderindex , 0 , inorder.size()-1 , mp) ;

        //method 2 using TC O(N) yha hum range wala concept use kr rhe hai 

        int mini = INT_MIN ;
        int maxi = INT_MAX ;
        int index = 0 ;

        return solve1(preorder , mini , maxi , index) ;



    }
};
