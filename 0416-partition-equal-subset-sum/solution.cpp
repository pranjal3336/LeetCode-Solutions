class Solution {
public:
    bool solve(int index , vector<int>& nums , int target , vector<vector<int>>&dp ){
        if(index >= nums.size() || target <0){
            return false ; ;
        }

        if(target == 0 ){
            return true ;
        }

        if(dp[index][target] != -1){
            return dp[index][target] ;
        }

        bool include = solve(index+1 , nums , target- nums[index] , dp) ;
        bool exclude = solve(index+1 , nums , target , dp) ;

        return dp[index][target] = include or exclude ;

        
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size() ;
        int sum = 0 ;
        for(int i =0 ; i<n ; i++){
            sum+=nums[i]  ;
        }

        if(sum%2 != 0){//sum odd hai toh partition nhi ho skta 
            return false ;
        }

        int target = sum/2 ;//sum even tha isliye yha tk aae 
        vector<vector<int>>dp(n+1 , vector<int>(target+1 , -1)) ;
        return solve(0 , nums , target , dp) ;


    }
};
