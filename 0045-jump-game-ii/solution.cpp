class Solution {
public:
    int solve(vector<int>& nums , int i , int n , vector<int>&dp){
        if(i>=n-1){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i] ;
        }

        int ans = INT_MAX ;
        for(int j=1 ; j<= nums[i] ; j++){
            if(i+j<n){
                int temp = solve(nums , i+j , n , dp) ;
                if(temp != INT_MAX){
                    ans = min(ans , 1+ temp) ;
                }
                
            }
            
        }

        return dp[i] = ans ;
    }

    int jump(vector<int>& nums) {
        int n = nums.size() ;
        vector<int>dp(n+1 , -1) ;
        return solve(nums , 0 , n , dp) ;
    }
};
