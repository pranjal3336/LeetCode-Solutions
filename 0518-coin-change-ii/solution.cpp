class Solution {
public:
    int solve(int amount, vector<int>& coins , int i , int sum , vector<vector<int>>&dp){
        if(sum == amount){
            return 1 ;
        }
        
        if(i>=coins.size() || sum > amount){
            return 0 ;
        }

        if(dp[i][sum] != -1){
            return dp[i][sum] ;
        }
            int include = solve(amount , coins , i , sum+coins[i] , dp) ;
            int exclude = solve(amount , coins , i+1 , sum , dp) ;

           int  ans = include + exclude ;
        

        return  dp[i][sum] = ans ;
        
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , -1)) ;
        return solve(amount , coins , 0 , 0 , dp) ;
    }
};
