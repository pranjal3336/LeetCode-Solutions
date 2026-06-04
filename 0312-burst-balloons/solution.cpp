class Solution {
public:
    int solve(int i , int j , vector<int>& nums , vector<vector<int>>&dp){
        //base case 
        if(i>j){
            return 0 ;
        }
        if(dp[i][j] != -1){
            return dp[i][j] ;
        }

        int maxi = INT_MIN ;
        for(int k = i ; k<=j ; k++){
            int coins = (nums[i-1]*nums[k])*nums[j+1] + solve(i , k-1 , nums , dp) + solve(k+1 , j , nums , dp) ;
            maxi =  max(maxi , coins) ;
        }

        return dp[i][j] = maxi ;
    }
    int maxCoins(vector<int>& nums) {
         int n = nums.size() ;
         nums.insert(nums.begin() , 1) ;
         nums.push_back(1) ;//now nums = [1,3,1,5,8,1] i = 1 and j = 4 
         int m = nums.size() ;
         vector<vector<int>>dp(m+1 , vector<int>(m+1 , -1)) ;
         return solve(1, n , nums , dp) ;  
    }
};
