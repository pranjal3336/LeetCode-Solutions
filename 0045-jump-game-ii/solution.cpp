class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0 ;
        int maxEnd = 0 ;
        int currEnd = 0 ;

        int i =0 ;
        int n = nums.size() ;
      

        while(i<n){
            if(i>currEnd){
                ans++ ;
                currEnd = maxEnd ;
            }
            maxEnd = max(maxEnd , i+nums[i]) ;
            i++ ; 
        }

        return ans ;
    }
};
