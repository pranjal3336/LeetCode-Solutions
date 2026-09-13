class Solution {
public:
    void solve(vector<int>&nums , int i , vector<int>&temp , vector<vector<int>>&ans){
        //base case 
        if(i>=nums.size()){
            ans.push_back(temp) ;
            return ;
        }

        temp.push_back(nums[i]) ;//including current number
        //case 1 --> include krne ke baad explore kr rhe 
        solve(nums , i+1 , temp , ans) ;
        temp.pop_back() ;//excluding current number 
        //case 2 exclude krne ke baad explore kr rhe
        solve(nums , i+1 , temp , ans) ;
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans ;
        vector<int>temp ;
        solve(nums , 0 , temp , ans) ;
        return ans ;
    }
};
