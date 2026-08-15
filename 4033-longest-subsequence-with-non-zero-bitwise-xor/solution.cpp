class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_all = 0;
        bool all_zeros = true;
        
        for (int x : nums) {
            xor_all ^= x;
            if (x != 0) {
                all_zeros = false;
            }
        }
        
        // If all elements are 0, no non-zero XOR subsequence is possible
        if (all_zeros) {
            return 0;
        }
        
        // If the total XOR is already non-zero, take the whole array
        if (xor_all != 0) {
            return nums.size();
        }
        
        // If total XOR is 0 but there are non-zero elements, exclude one element
        return nums.size() - 1;
    }
};
