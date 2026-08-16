class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {0};
        for (int stone : stones) {
            cnt[stone % 3]++;
        }
        
        // If count of multiples of 3 is even, they don't force a parity switch effect
        if (cnt[0] % 2 == 0) {
            return cnt[1] > 0 && cnt[2] > 0;
        }
        
        // If count of multiples of 3 is odd, parity flips
        return abs(cnt[1] - cnt[2]) > 2;
    }
};
