class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        int i = 0 ;
        int j = 0 ;
        int l = 1;
        int maxi = nums[0] ;
        int mini = nums[0] ;
        
        while(j<n){
           maxi = nums[j] ;
           mini = nums[i] ;
            while(maxi > (long long)k*mini){
                i++ ;
                mini = nums[i] ;
                
            }
            l = max(l , j-i+1) ;
            j++ ;

        }
        return n-l ;

    }
};
