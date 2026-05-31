class Solution {
public:
    int solve(vector<int>& coins , int amount ,  vector<vector<int>>&dp , int index ){
        if(amount == 0 ){
            return 1 ;
        }
        if(amount < 0 || index >= coins.size()){
            return 0 ;
        }

        if(dp[index][amount] != -1){
            return dp[index][amount] ;
        }

        int include = solve(coins , amount-coins[index] , dp , index) ;//index same rhega kyonki infinte supply hai 
        int exclude = solve(coins , amount , dp , index+1 ) ;//exclude krenge toh aage bd jayga 
        int ans = include + exclude ;

        return dp[index][amount] = ans ;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(amount+1 , -1)) ;
        return solve(coins , amount , dp , 0) ;
    }
};
