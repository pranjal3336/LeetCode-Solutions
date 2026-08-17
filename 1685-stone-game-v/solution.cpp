class Solution {
public:
    int f[501][501];
    int dfs(vector<int>& a, vector<int>& s, int l, int r) {
        if (l == r) return 0;
        if (f[l][r] != -1) return f[l][r];
        int& ans = f[l][r];
        ans = 0;
        for (int k = l; k < r; ++k) {
            int s1 = s[k] - (l == 0 ? 0 : s[l - 1]);
            int s2 = s[r] - s[k];
            if (s1 >= s2) ans = max(ans, s2 + dfs(a, s, k + 1, r));
            if (s1 <= s2) ans = max(ans, s1 + dfs(a, s, l, k));
        }
        return ans;
    }
public:
    int stoneGameV(vector<int>& stoneValue) {
        memset(f, -1, sizeof(f));
        vector<int> s(stoneValue.size());
        partial_sum(stoneValue.begin(), stoneValue.end(), s.begin());
        return dfs(stoneValue, s, 0, stoneValue.size() - 1);
    }
    
};
