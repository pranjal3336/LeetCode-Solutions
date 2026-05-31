class Solution {
public:
    int solve(int i , int sum , vector<int>&nums , vector<vector<int>>&dp){
       if(i == nums.size()){
        if(sum == 0){
            return 1 ;
        }
        else{
            return 0 ;
        }
       }

        if(dp[i][sum] != -1){
            return dp[i][sum] ;
        }
        int include = 0;
        if(sum - nums[i] >=0){
            include = solve(i+1 , sum - nums[i] , nums , dp) ;
        }

        int exclude = solve(i+1 , sum , nums ,dp) ;

        int ans = include + exclude ;
        return dp[i][sum] = ans ;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size() ;
        int totalsum = 0 ;
        for(int i =0 ; i <n ; i++){
            totalsum+=nums[i] ;
        }

        //iss question ko bhi aese dekha jaa skta hai s1 - s2 = target kyonki ek set mai saare + sign wale aayenge and ek set mai saare _ sign wale and - sign unn sab mai se common leke bahr aa jayga and suset 2 mai bhi voh sab add hi ho rhe honge phir 
        //jaise two sebsetsum ka difference equal to target  
        // s1 = {1,1,1,1} = 4 and  s2 = {1} = 1 and 4-1 =3 
        //yeh question bhi same Count Partitions with Given Difference yeh wale question ki trh hai bs language change hai 
        //s1-s2 =d
        //totalsum -s2 -s2 =target  kyonki s1+s2 = totalsum hoga s1 ko replce kr rhe hai 
        //(totalsum-target)/2 = s2 aaya yaani aese subset count krne hai j0 lhs satisfy kre 
        if(totalsum-target <0 || (totalsum-target)%2 != 0){
            return 0 ;
        }
        int sum = (totalsum-target)/2 ;
        vector<vector<int>>dp(n+1 , vector<int>(sum+1 ,-1)) ;
        return solve(0 ,sum ,nums , dp ) ;
        
    }
};
