class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;
        int sum = accumulate(begin(nums) , end(nums) , 0) ;
        int x = n*(n+1)/2 ;

        return x-sum ;
    }
};
