class Solution {
public:
    //recursion + memoization 
    int solve(string &a , string &b , int i , int j , vector<vector<int>>&dp){
        if(i == a.length() ){
            return 0 ;
        }
        if(j == b.length()){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }
        int ans = 0 ;
        if(a[i] == b[j]){
            ans = 1 + solve(a , b , i+1 , j+1 , dp) ;
        }
        else{
            ans = max(solve(a , b , i+1 , j , dp) , solve(a , b , i , j+1 , dp)) ;
        }
        dp[i][j] = ans ;
        return dp[i][j] ;
    }
    //using tabulation 
    int solve1(string a, string b){
        int n = a.length() ;
        int m = b.length() ;
        vector<vector<int>>dp(n+1 , vector<int>(m+1 , 0)) ;

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = m-1 ; j>=0 ; j--){
                int ans = 0 ;
                if(a[i] == b[j]){
                    ans = 1 + dp[i+1][j+1] ;
                }
                else{
                    ans = max(dp[i+1][j]  , dp[i][j+1] ) ;
                }
                dp[i][j] = ans ;
            }
        }
        return dp[0][0] ;
    }




    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length() ;
        // int m = text2.length() ;
        // vector<vector<int>>dp(n+1 , vector<int>(m+1 , -1)) ;
        // return solve(text1 , text2 , 0 , 0 , dp) ;

        return solve1(text1 , text2) ;
    }
};
