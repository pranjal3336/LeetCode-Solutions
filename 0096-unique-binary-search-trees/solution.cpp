class Solution {
public:
    //top down approach or recursion + memoization 
    //BST mai root ke left mi chote and right mai bde nodes hote hai
    int solve(int n , vector<int>& dp){
        if(n<=1){
            return 1 ;
        }

        if(dp[n] != -1){
            return dp[n] ;
        }
        int ans = 0 ;
        //ab hum i ko as a root maanegeg and no of unique bst nikalenge for all i from 1 to n
        for(int i= 1 ; i<=n ;i++){
            ans = ans + ( (solve(i-1 ,dp))*(solve(n-i , dp)) ) ; // i ke left mai i-1 nodes honge and i ke right mai n-i nodes honge 
        }

        return dp[n] = ans ;
    }
    int numTrees(int n) {
        vector<int>dp(n+1 , -1) ;
        return solve(n , dp) ;
    }
};
