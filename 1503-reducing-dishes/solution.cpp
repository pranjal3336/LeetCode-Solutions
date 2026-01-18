class Solution {
public:
    //recursion + memoization 
    int solve(vector<int>& satisfaction , int index , int time ,vector<vector<int>>&dp ,  int n ){
        //base case yaani hum satisfaction wale array se bahr nikl chuke h
        if(index == n){
            return 0 ;
        }

        if(dp[index][time] != -1){
            return dp[index][time] ;
        }

        int include = satisfaction[index]*(time+1) + solve(satisfaction , index+1 , time+1 , dp ,n) ;
        int exclude = 0 + solve(satisfaction , index+1 , time , dp ,n) ;//jab hum exclude kr rhe h toh hum time same lenge and contribution mai kuch add nhi hoga isliye 0 likha h 

        dp[index][time] = max(include , exclude) ;
        return  dp[index][time] ;

    }

    //method 2 using tabulation 
    int solve1(vector<int>& satisfaction){
        
        int n = satisfaction.size() ;
        vector<vector<int>>dp(n+1 , vector<int>(n+1 , 0)) ;

        for(int index = n-1 ; index >=0 ; index--){
            for(int time = index ; time>=0 ; time--){
                int include = satisfaction[index]*(time+1)+ dp[index+1][time+1] ;
                int exclude = 0 + dp[index+1][time] ;

                dp[index][time] = max(include , exclude) ;          
            }
        }

        return dp[0][0] ; // yeh bottom up approach h isliye hume answer dp[0][0] mai milega 

    }

    //method 3 space optimization yha hum dp array ki bjay sirf 2 vectors ka use krenge kyonki dp[index][time] sirf next row yaani dp[index+1] pr depend kr rha h jha bhi index+1 h vha next array and jha index likha h vha curr array use krenge 
    int solve2(vector<int>& satisfaction){
        
        int n = satisfaction.size() ;
        
        vector<int>curr(n+1 , 0) ;
        vector<int>next(n+1 , 0) ;

        for(int index = n-1 ; index >=0 ; index--){
            for(int time = index ; time>=0 ; time--){
                int include = satisfaction[index]*(time+1)+ next[time+1] ;
                int exclude = 0 + next[time] ;

                curr[time] = max(include , exclude) ;          
            }
            next = curr ; //hume next array mai curr ki value daalnei h yaani har iteration ke baad curr wala ab next bn chuka hoga kyonki hum upr move kr rhe h 
        }

        return next[0] ; // yeh bottom up approach h isliye hume answer dp[0][0] mai milega 

    }
    int maxSatisfaction(vector<int>& satisfaction) {
        //phle hume sort krna h 
        // sort(satisfaction.begin() , satisfaction.end()) ;
        // int n = satisfaction.size() ;
        // vector<vector<int>>dp(n+1 , vector<int>(n+1 , -1)) ;
        // return solve(satisfaction , 0 , 0 , dp , n) ;
        // sort(satisfaction.begin() , satisfaction.end()) ;
        // return solve1(satisfaction) ;

        sort(satisfaction.begin() , satisfaction.end()) ;
        return solve2(satisfaction) ;
    }
};
