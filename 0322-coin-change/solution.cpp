class Solution {
public:

    int solve(int n ,vector<int>& coins , vector<int>&dp , int amount){
        if(amount==0){
            return 0 ;
        }
        if(amount < 0){
            return INT_MAX ;
        }

        if(dp[amount]!= -1){
            return dp[amount] ;
        }

        int mincoins = INT_MAX;
        for(int i =0 ; i<n ; i++){
            int ans = solve(n , coins , dp , amount-coins[i]) ;

            if(ans != INT_MAX){
                mincoins = min(mincoins , 1+ ans) ;
            }
        }

        return dp[amount] = mincoins ;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size() ;
        vector<int>dp(amount+1 , -1) ;
        int ans = solve(n , coins , dp , amount);
        if(ans == INT_MAX){
            return -1 ;
        }
        else{
            return ans ;
        }

    }
};
