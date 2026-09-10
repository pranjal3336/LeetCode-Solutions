class Solution {
public:
    bool solve(int i , int j , string&s , vector<vector<int>>&dp){
        if(i>=j){
            return true ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        if(s[i] == s[j]){
            return dp[i][j] = solve(i+1 , j-1 ,s , dp) ;
        }
        else{
            return dp[i][j] =  false ;
        }
    }
    string longestPalindrome(string s) {
        vector<vector<int>>dp(s.length()+1 , vector<int>(s.length()+1 , -1)) ;
        int maxlength = INT_MIN ;
        int startpos = -1 ;
        for(int i =0 ; i<s.length() ; i++){
            for(int j = i ; j<s.length() ; j++){
                if(solve(i , j , s , dp)){
                    if(j-i+1 > maxlength){
                        maxlength = j-i+1 ;
                        startpos = i ;
                    }   
                }
            }
        }

        return s.substr(startpos , maxlength) ;
    }
};
