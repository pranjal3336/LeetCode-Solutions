class Solution {
public:
    bool solve(string &input  , string &pattern , int i , int j , vector<vector<int>>&dp){
        //base case 
        if(i<0 && j<0){
            return true ;
        }
        if(i>=0 && j<0){
            return false ;
        }

        if(i<0 && j>=0){
            for(int k =0 ; k<=j ; k++){
                if(pattern[k] != '*'){
                    return false ;
                }
            }
            return true ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        //match wali condition 
        if(input[i] == pattern[j] || pattern[j] == '?'){//first condition bta rhi hai ki input and pattern ka character same hai toh hum next yaani i-1 and j-1 krenge kyonki hum last to first traverse kr rhe h and second condtion bta rhi hai ki pattern of j agr ? hai toh bhi i-1 and j-1 krenge kyonki hum ? ko kisi bhi single character se replace kr skte h
            return dp[i][j] = solve(input , pattern , i-1 , j-1 ,dp) ;
        }
        else if(pattern[j] == '*'){
            //yha 2 rule lgenge ek baar * ko empty se replace krenge and ek * ko * and sath string wala alphabet likh denge jisse i-1 hoga and j pointer star pr hi rhega 
            return dp[i][j] =  (solve(input , pattern , i-1 , j , dp) || solve(input, pattern , i , j-1 , dp)) ; // yha hum * ko ya toh empty string se replace kr rhe h jisme hum j-1 kr rhe hai i same rhega and hum * ko *.[jo character input mai hai] usse replace kr rhe h yeh imagine kr rhe hai hum and input ke character ko ek trh se kaat rhe hai and pattern mai pointer * pr hi rhega and i , i-1 ho jayga 
        }
        else{
            return false ;
        }
    }
    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length() , vector<int>(p.length() ,-1 )) ;
        return solve(s , p , s.length()-1 , p.length()-1 , dp) ;
    }
};
