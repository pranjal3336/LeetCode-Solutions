class Solution {
public:
    bool solve(vector<int>& nums , int i , int target , vector<vector<int>>&dp){
        //base case 
        if(target == 0){
            return true ;
        }
        if(i>=nums.size() || target <0){
            return false ;
        }

        if(dp[i][target] != -1 ){
            return dp[i][target] ;
        }

        bool include = solve(nums , i+1 , target - nums[i] , dp) ;
        bool exclude = solve(nums , i+1 , target , dp) ;

        return dp[i][target] =  include or exclude ;
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(begin(nums) , end(nums) , 0) ;
        if(sum%2 != 0){
            return false ;
        }

        int target = sum/2 ;
        int n = nums.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1)) ;

        return solve(nums , 0 , target , dp) ;
    }
};
