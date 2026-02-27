class Solution {
public://hume word1 ko word2 bnana hai isliye jo bhi modification hogi woh word1 yaani a string mai hogi ussi ke pointer ke sath khelenge yaani i ke saath 
    int solve(string &a , string &b , int i , int j , vector<vector<int>>&dp){
        //base cases 
        if(i == a.length()){
            return b.length() - j ;
        }

        if(j == b.length()){
            return a.length() - i ;
        }

        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int ans = 0 ;
        if(a[i] == b[j]){
            return  dp[i][j] = solve(a , b , i+1 , j+1 , dp) ;
        }
        else{

            //insert kr skte hai 
            //hum 1 add kr rhe hai kyonki iss operation ko bhi toh count krenge 
            int insertAns = 1 + solve(a , b , i , j+1 ,dp) ; //hum actual mai insert nhi kr rhe hum imagine kr rhe hai ki humne insert kra hai and woh word2 yaani b se matc ho gya hai isliye j ko aage bdaya hai i ko nhi kyonki insert krne pr pointer peeche jaana chahiye then aage bdega 

            //delete kr skte hai 
            int deleteAns = 1+solve(a , b , i+1 , j ,dp) ;//hum isme bhi imagine kr rhe h actual mai delete nhi kr rhe hai 

            //replace kr skte hai 
            int replaceAns = 1 + solve(a , b , i+1 , j+1 ,dp) ;//similarly above 

            ans =  min(insertAns , min(deleteAns , replaceAns))  ;

        }
         dp[i][j] = ans ;
        return dp[i][j] ;

    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length() , vector<int>(word2.length(),-1)) ;
        return solve(word1 , word2 , 0 ,0 , dp) ;
    }
};
