class Solution {
public:
    int solve(int prev , int curr , vector<int>& nums , int n , vector<vector<int>>&dp){
        if(curr == n){
            return 0 ;
        }

        if(dp[prev+1][curr] != -1){
            return dp[prev+1][curr] ;
        }

        int include = 0 ;
        if(prev == -1 || nums[curr]> nums[prev]){
            include = 1 + solve(curr , curr+1 , nums , n , dp) ;
        }
        int exclude = solve(prev , curr+1 , nums , n , dp) ;

        return dp[prev+1][curr] =  max(include , exclude) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)) ;
        return solve(-1 , 0 , nums , n , dp) ;
    }
};
