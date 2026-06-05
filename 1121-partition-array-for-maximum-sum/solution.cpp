class Solution {
public:
    int solve(int i , int n ,vector<int>& arr, int k , vector<int>&dp){
        //base case 
        if(i==n){
            return 0 ;
        }

        if(dp[i] != -1){
            return dp[i] ;
        }

        int ans = INT_MIN ;
        int maxi = INT_MIN ;
        for(int j =0 ; j<k;j++){
            if(i+j<n){
                maxi = max(arr[i+j] ,maxi) ;
                int sum = maxi*(j+1) + solve(i+j+1 , n , arr ,k , dp) ;
                ans = max(ans , sum) ;
            }  
        }

        return dp[i] = ans ;


    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size() ;
        vector<int>dp(n+1 , -1) ;
        return solve(0 , n , arr , k , dp) ;
    }
};
