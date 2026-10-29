class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        
        int xorall = 0 ;
        for(int &num : nums){
            xorall ^= num ;
        }
        

        //int t = (xorall ^ k) ;
        return __builtin_popcount(xorall ^ k) ;

    }
};
