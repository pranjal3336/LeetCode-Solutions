class Solution {
public:
    int solve(vector<int>& nums , int curr , int prev , vector<vector<int>>&dp){
        if(curr == nums.size()){
            return 0 ;
        }

        if(dp[curr][prev+1] != -1){
            return dp[curr][prev+1] ;
        }
        int include  = 0 ;
        if(prev == -1 || nums[curr] > nums[prev]){
            include = 1 + solve(nums , curr+1 , curr , dp) ;
        }

        int exclude = solve(nums , curr+1 , prev , dp) ;

        return dp[curr][prev+1]  = max(include , exclude) ;
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size() ;
        vector<vector<int>>dp(n , vector<int>(n+1  , -1)) ;// prev ki range  -1 to n-1 tk hai means n+1 index hai par -1 index nhi hota isliye hum 0 to n indexing maanenge isliye jha bhi prev likhna hoga vha prev=1 likhenge 
        return solve(nums , 0 , -1 , dp) ;
    }
};
