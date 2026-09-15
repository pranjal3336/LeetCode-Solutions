class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        int l = 0 ;
        int r = n -1 ;
        int mod = 1e9+7 ;
        vector<long long>power(n , 1) ;//precompute kr rhe hai power ko 
        for(int i =1 ; i<n ; i++){
            power[i] = (power[i-1]*2)%mod ;
        }

        int res = 0 ;
        while(l<=r){
            if(nums[l] + nums[r] <= target){
               res = (res + power[r-l])%mod ;
                l++ ;
            }
            else{
                r-- ;
            }
        }
        return res ;
    }
};
