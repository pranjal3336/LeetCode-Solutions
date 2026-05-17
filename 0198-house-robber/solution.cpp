class Solution {
public:
    int solve(int n ,vector<int>& nums , vector<int>&dp ){
        if(n<0){
            return 0 ;
        }
        if(n==0){
            return nums[0] ;
        }
        if(dp[n] != -1){
            return dp[n] ;
        }

        int include = solve(n-2 , nums ,dp) + nums[n] ;
        int exclude = solve(n-1 , nums , dp) + 0 ;
        dp[n] = max(include , exclude) ;
        return dp[n] ;
    }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n+1 , -1) ;
        int ans = solve( n-1 , nums , dp) ;
        return ans ;
    }
};
