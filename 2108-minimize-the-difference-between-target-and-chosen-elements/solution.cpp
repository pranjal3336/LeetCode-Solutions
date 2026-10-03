class Solution {
public:
    int solve(int i , int sum ,vector<vector<int>>& mat , int target , int n , vector<vector<int>>&dp){

        if(i>=n){
            return abs(sum - target) ;
        }

        if(dp[i][sum] != -1){
            return dp[i][sum] ;
        }
        int ans = INT_MAX ;

        for(int j:mat[i]){

            int temp = solve(i+1 , sum+j , mat , target , n , dp) ;
            ans = min(ans , temp) ;
        }

        return dp[i][sum] = ans ;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int n = mat.size() ;
        vector<vector<int>>dp(n , vector<int>(5000 , -1)) ;
        return solve(0 ,  0 , mat , target , n , dp) ;
    }
};
