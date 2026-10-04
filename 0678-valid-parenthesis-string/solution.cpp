class Solution {
public:
    // bool solve(int i , int n , string s , int open  , vector<vector<int>>&dp){
    //     if(i== n){
    //         return open==0 ;
    //     }

    //     if(dp[i][open] != -1){
    //         return dp[i][open] ;
    //     }

    //     bool ans = false ;
    //     if(s[i] == '('){
    //         ans = solve(i+1 ,n , s , open+1 , dp) ;
    //     }
    //     else if(s[i] == '*'){
    //         //case 1 : * ko (  yeh le lo 
    //         ans |= solve(i+1 ,n , s , open+1 , dp) ;
    //         //case 2 : * ko ) ye lo 
    //         //ek check lga rhe hai ki open >0 hoga tbhi -1 krenge 
    //         if(open>0){
    //             ans |= solve(i+1 ,n , s , open-1 , dp) ;
    //         }
    //         //case 3 : * ko ' ' empty le le 
    //         ans |= solve(i+1 , n ,s , open , dp) ;
    //     }
    //     else if(open>0){
    //             ans |= solve(i+1 ,n , s , open-1, dp) ;
    //     }

    //     return dp[i][open] =  ans ;
    // }
    bool checkValidString(string s) {
        int n = s.length() ;
        // int open = 0 ;
        // vector<vector<int>>dp(n , vector<int>(n , -1)) ;
        // return solve(0 , n , s , open , dp) ;

        //method 2 
        //phle left to right jayenge 
        int open = 0 ;
        bool res = true ;
        for(int i=0;i<n ; i++){
            if(s[i] == '(' || s[i] == '*'){
                open++ ;
            }
            else {
                open-- ;
            }
            if(open <0){
                res = false ;
                break ;
            }
        }

        int close = 0 ;
       
        for(int i=n-1;i>=0 ; i--){
            if(s[i] == ')' || s[i] == '*'){
                close++ ;
            }
            else {
                close-- ;
            }
            if(close <0){
                res = res and false ;
                break ;
            }
        }

        return res;

    }
};
