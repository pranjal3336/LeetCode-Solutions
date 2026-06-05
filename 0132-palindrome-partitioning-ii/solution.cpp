class Solution {
public:
    bool check(int i , int j ,string &s){
       
        while(i<j){
            if(s[i] != s[j]){
               return false ;
            }
            i++ ;
            j-- ;
        }
        return true ;
    }
    int solve(int i ,int n , string &s , vector<int>&dp) {
        //base case 
        if(i == n){
            return 0 ;
        }
        if(dp[i] != -1){
            return dp[i] ;
        }
        
        int ans = INT_MAX ;
        for(int j = i ; j <n  ; j++){
            if(check(i , j , s) == true ){//hum jo ab tak k to i tk ki string hai usse check kr rhe hai ki palindrome hai ya nhi agr hai tbhi partition krenge 
                int cut = 1 + solve(j+1 , n , s , dp) ;
                ans = min(ans , cut) ;
            }
           
        }

        return dp[i] = ans ;
    }
    int minCut(string s) {
        int n = s.length() ;
        vector<int>dp(n+1 , -1) ;
        return solve(0 , n , s , dp) -1 ; // 1 minus kr rhe hai kyonki function last mai mai partition kr rha hai jab string khtm ho chuki hai 
    }
};
