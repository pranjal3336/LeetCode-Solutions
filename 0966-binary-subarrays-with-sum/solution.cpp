class Solution {
public:
    int solve(vector<int>&nums , int goal){
         int n = nums.size() ; 
        if(goal < 0){
            return 0 ;
        }
        int sum = 0 ;
        int i =0 , j=0;
        int cnt = 0 ;
        while(j<n){
            sum += nums[j] ;

            while(sum > goal){
                sum -= nums[i] ;
                i++ ;
            }
            cnt += (j-i+1) ;
            j++ ;
        }

        return cnt ;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        //method 1 using prefix sum 
        // int n = nums.size() ; 
        // int i =0 ;
        // int ans = 0 ;
        // unordered_map<int , int>mp ;
        // mp[0] = 1 ;
        // int sum = 0 ;
        // while(i<n){
        //     sum += nums[i] ;
            
        //     if(mp.find(sum - goal) != mp.end()){
        //         ans+=mp[sum-goal] ;
        //     }
        //     mp[sum]++ ;
        //     i++ ;
        // }

        // return ans ;

        //method 2 
       
        int cnt1 = solve(nums , goal) ;
        int cnt2 = solve(nums , goal-1) ;

        return cnt1-cnt2 ;

    }
};
