class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;
        int maxEnd = 0 ;
        int currEnd = 0 ;

        if(n == 1){
            return true ;
        }

        int i=0 ;
        while(i<n){
            if(i>maxEnd){
                return false ;
            }
            maxEnd = max(maxEnd , i+nums[i]) ;
            i++ ;
        }

        return true  ;
    }
};
