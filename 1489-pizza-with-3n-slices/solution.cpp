class Solution {
public:

    //method 1 --> recursion + memoization 
    //yeh question same house robery wale ki trh hai hum 2 case le rhe hai agr 0th index se start kr rhe hai toh last wala nhi le rhe isliye k-2 tk liya hai 
    //agr 1th index se start kr rhe hai toh last wala le skte hai kyonki yeh circular nature mai hai 
    int solve(int startIndex , int endIndex , vector<int>& slices, int n , vector<vector<int>>&dp){
        if(n==0 || startIndex > endIndex){
            return 0 ;
        }

        if(dp[startIndex][n] != -1){
            return dp[startIndex][n] ;
        }

        int include = slices[startIndex] + solve(startIndex + 2 , endIndex , slices , n-1 , dp) ;
        int exclude = 0 + solve(startIndex + 1 , endIndex , slices , n , dp) ;

        dp[startIndex][n] = max(include , exclude) ;
        return dp[startIndex][n] ;
    }

    // method  2 --> using tabulation // bottom up approach hai upr wale method mai hum startIndex 0 ya 1 se k-2 ya k-1 tk le rhe the and n ko k/3 se 0 tk but ab yha hum ulta kr denge 
    

    int solve1(vector<int>& slices){
       int k = slices.size() ;
       vector<vector<int>>dp1(k+2 , vector<int>(k+2 , 0)) ;
       vector<vector<int>>dp2(k+2 , vector<int>(k+2 , 0)) ;
       //hume base case ki need nhi hai kyonki humne dp vector 0 se initialize kr rkhe hai 

       for(int startIndex = k-2 ; startIndex>=0 ; startIndex--){
            for(int n = 1 ; n<= k/3 ; n++){
                int include = slices[startIndex] + dp1[startIndex + 2][n-1] ;
                int exclude = 0 + dp1[startIndex + 1][n] ;

                dp1[startIndex][n] = max(include , exclude) ;
                
            }
       }
       int case1 = dp1[0][k/3] ;

       for(int startIndex = k-1 ; startIndex>=1 ; startIndex--){
            for(int n = 1 ; n<= k/3 ; n++){
                int include = slices[startIndex] + dp2[startIndex + 2][n-1] ;
                int exclude = 0 + dp2[startIndex + 1][n] ;

                dp2[startIndex][n] = max(include , exclude) ;
                
            }
       }
       int case2 = dp2[1][k/3] ;
       return max(case1 , case2) ;

    }


    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size() ;

        // vector<vector<int>>dp1(k , vector<int>(k , -1)) ;
        // int case1 = solve(0 , k-2 , slices , k/3 , dp1 ) ;
        
        // vector<vector<int>>dp2(k , vector<int>(k , -1)) ;
        // int case2 = solve(1 , k-1 , slices , k/3 , dp2);
        
        // return max(case1 , case2) ;

        return solve1(slices) ;
    }
};
