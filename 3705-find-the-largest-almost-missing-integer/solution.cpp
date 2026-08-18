class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int , int>mp ;
        int n = nums.size() ;
        for(int i=0 ; i<n ; i++){
            mp[nums[i]]++ ;
        }
        int ans = -1 ;
        if(k == 1){
            for(auto it:mp){
                if(it.second == 1){
                    ans = max(ans , it.first) ;
                }
            }
            return ans ;
        }

        if(k == n){
            return *max_element(begin(nums) , end(nums)) ;
        }
        

        if(mp[nums[0]] ==1 && mp[nums[n-1]] == 1){
            return max(nums[0] , nums[n-1]) ;
        }
        else if(mp[nums[0]] >1 && mp[nums[n-1]] == 1){
            return nums[n-1] ;
        }
        else if(mp[nums[0]] ==1 && mp[nums[n-1]] > 1){
            return nums[0] ;
        }
        return -1 ;
    }
};
