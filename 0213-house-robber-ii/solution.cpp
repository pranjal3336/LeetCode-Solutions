class Solution {
public:

    int solve( int n , vector<int>& nums , vector<int>&dp ){
      
      if(n<0){
          return 0 ;
      }
      
      if(n == 0){
          return nums[0] ;
      }
      
      if(dp[n] != -1){
          return dp[n] ;
      }
      
      int include = solve(n-2 ,  nums , dp ) +   nums[n] ;
      int exclude = solve(n-1 ,  nums , dp ) +   0 ;
      
      dp[n] = max(include , exclude) ;
      return dp[n] ;
  }
    int rob(vector<int>& nums) {
        int n = nums.size() ;
        if(n==1) return nums[0] ;
        
        vector<int>dp1(n+1 , -1) ;
        vector<int>dp2(n+1 , -1) ;

        vector<int>first ;
        vector<int>second ;

        for(int i =0 ; i<n ; i++){
            //first array way last element nhi le rhe kyonki last wala first ka neighbour ho jayga 
            if(i!= n-1){
                first.push_back(nums[i]) ;
            }
            //second array mai first element nhi rkh rhe 
            if(i!=0){
                second.push_back(nums[i]) ;
            }
        }

        int ans1 = solve(first.size()-1 , first , dp1) ;
        int ans2 = solve(second.size()-1 , second , dp2) ;

        int ans = max(ans1 , ans2) ;
        return ans ;



    }
};
