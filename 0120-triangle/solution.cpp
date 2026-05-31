class Solution {
public:
    //method 1 top down or memoization and TC O(N*N) and SC(N*N)
    // int solve(int i , int j , int n , vector<vector<int>>& triangle ,  vector<vector<int>>&dp){
    //     //base case 
    //     if(i >=n){
    //         return 1e9 ;
    //     }
    //     if(i == n-1){
    //         return triangle[i][j] ;
    //     }
    //     if(dp[i][j] != 1e9){
    //         return dp[i][j] ;
    //     }   
    //    int down = triangle[i][j] + solve(i+1 , j , n , triangle , dp) ;
    //    int downrightdigonal = triangle[i][j] + solve(i+1 , j+1 , n , triangle , dp) ;
    //    int ans = min(down ,downrightdigonal ) ;//hum current row pr agr j index pr hai toh hum new row yaani i+1 mai sirf j and j+1 column hi jaa skte hai isliye 2 function call jaygi and jha minimum aayga voh lenge 

    //     return dp[i][j] =  ans ;

    // }

    //tabulation method --> bottom up approach  TC O(N*N) and SC O(N*N)

    int solve1(vector<vector<int>>& triangle){
         int n = triangle.size() ;
        vector<vector<int>>dp(n , vector<int>(n , 0)) ;

        for(int j = 0 ; j<n ; j++){
            dp[n-1][j] = triangle[n-1][j] ; //sabse phle last row se start kr rhe hai and dp ke last ke each column vhi corresponding value aayhi 
        }

        for(int i = n-2 ; i>=0 ; i--){
            for(int j = i ; j>=0 ; j--){
                 int down = triangle[i][j] + dp[i+1][j]  ;
                int downrightdiagonal = triangle[i][j] + dp[i+1][j+1] ;
                dp[i][j] =  min(down , downrightdiagonal) ;
            }
        }

        return dp[0][0] ;

    }

    //method 3 space optimization kyonki current row ki values sirf next row se calculate ho rhe hai toh hum 2 vector bnakr bhi kr skte hai 
    int solve2(vector<vector<int>>& triangle){
         int n = triangle.size() ;
        vector<int>front(n ,  0) ;// yeh ith row yaa kh skte hai i+1 ko srow ko show kr rha h
         vector<int>curr(n , 0) ;// yeh i-1 th yaa i th row mtlb front se upr wali row ko show kr rha hai and iski value front ke eleensts se calculate hogi 

        for(int j = 0 ; j<n ; j++){
            front[j] = triangle[n-1][j] ; //sabse phle last row se start kr rhe hai and dp ke last ke each column vhi corresponding value aayhi 
        }
        for(int i = n-2 ; i>=0 ; i--){
            for(int j = i ; j>=0 ; j--){
    
                 int down = triangle[i][j] + front[j]  ;
                int downrightdiagonal = triangle[i][j] + front[j+1] ;
                curr[j] =  min(down , downrightdiagonal) ;
            }

            front = curr ;
        }

        return front[0] ;

    }


    int minimumTotal(vector<vector<int>>& triangle) {
        // int n = triangle.size() ;
        // vector<vector<int>>dp(n , vector<int>(n , 1e9)) ;  
        // return solve(0,0,n,triangle , dp) ;

        //return solve1(triangle) ;

        return solve2(triangle) ;
    }
};
