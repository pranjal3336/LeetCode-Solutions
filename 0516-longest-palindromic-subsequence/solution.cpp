class Solution {
public:
    //iss question ko hum jo given string hai uska reverse krenge and usse bhi pass krenge as second string and un dono ka jo longest common subsequence hoga vhi iss ques ka answer yaani longest palindromin subsequence hoga 
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
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0)) ;

        for(int i = n-1 ; i>=0 ; i--){
            for(int j = n-1 ; j>=0 ; j--){
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
    int longestPalindromeSubseq(string s) {
         string revStr = s ;
         reverse(revStr.begin() , revStr.end()) ;
        //  int n = s.length() ;
        //  vector<vector<int>>dp(n , vector<int>(n , -1)) ;
        // return solve(s , revStr , 0 , 0 , dp) ;
        return solve1(s , revStr) ;
    }
};
