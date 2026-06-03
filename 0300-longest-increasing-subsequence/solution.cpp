class Solution {
public:
    // int solve(vector<int>& nums , int curr , int prev , vector<vector<int>>&dp){
    //     if(curr == nums.size()){
    //         return 0 ;
    //     }

    //     if(dp[curr][prev+1] != -1){
    //         return dp[curr][prev+1] ;
    //     }
    //     int include  = 0 ;
    //     if(prev == -1 || nums[curr] > nums[prev]){
    //         include = 1 + solve(nums , curr+1 , curr , dp) ;
    //     }

    //     int exclude = solve(nums , curr+1 , prev , dp) ;

    //     return dp[curr][prev+1]  = max(include , exclude) ;
    // }
    int lengthOfLIS(vector<int>& nums) {
         int n = nums.size() ;
        // vector<vector<int>>dp(n , vector<int>(n+1  , -1)) ;// prev ki range  -1 to n-1 tk hai means n+1 index hai par -1 index nhi hota isliye hum 0 to n indexing maanenge isliye jha bhi prev likhna hoga vha prev+1 likhenge 
        // return solve(nums , 0 , -1 , dp) ;


        //optimized method 
        vector<int>dp(n , 1) ;//hum phle ek vector bna rhe hai jisme initially saari value 1 hogi kyonki each element lis hoga 
        int maxi = 1 ; 
        for(int i = 0 ; i<n ; i++){//phir hum traverse kr rhe hai and j ko 0 to i-1 index tk traverse kr rhe hai agr lis milega toh check krenge ki dp[j]+1 > dp[i] hai na 
        //eg nums = [5,4,11,16,8]
        //then initially dp = [1,1,1,1,1] after loop dp = [1,1,2,3,2] hogi and 3 means index 3rd tk lis ki length 3 aa chuki hai joki maximum bhi hai 
            for(int j = 0 ; j<i ; j++){
                if(nums[j]<nums[i] && dp[j]+1 > dp[i]){
                    dp[i] = dp[j] + 1 ;
                }
            }
            maxi = max(maxi , dp[i]) ;
        }

        return maxi ;

    }
};
