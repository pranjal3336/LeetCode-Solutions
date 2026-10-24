class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>mp ;
        int ans = 0 ; 
        int n = s.length() ;
        int i =0 ;
        int j = 0 ;
        while(i<n){
            while(j<n &&  mp[s[j]] <1 ){
                mp[s[j]]++ ;
                j++ ;
            }
            ans = max(ans , j-i) ;
            mp[s[i]]-- ;
            i++ ;
        }

        return ans ;
    }
};
