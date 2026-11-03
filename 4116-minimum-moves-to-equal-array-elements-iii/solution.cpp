class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = *max_element(begin(nums) , end(nums)) ;
        int moves = 0 ;
        int n = nums.size() ;
        for(int i =0 ; i<n ; i++){
            moves += maxi-nums[i] ;
        }
        return moves ;
    }
};
