class Solution {
public:
    int solve(int i , int j , string &a, string &b , vector<vector<int>>&dp){
        if(i>= a.length() || j>=b.length()){
            return 0 ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = 0 ;
        if(a[i] == b[j]){
            ans = 1 + solve(i+1 , j+1 , a , b , dp) ;
        }
        else{
            ans = max(solve(i+1 , j , a , b , dp) , solve(i , j+1 , a ,b , dp)) ;
        }
        return dp[i][j] =  ans ;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.length()+1 , vector<int>(text2.length()+1 , -1)) ;
        return solve(0,0, text1 , text2 , dp) ;
    }
};
