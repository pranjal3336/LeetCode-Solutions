class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char , int>mp ;
        if(s.length() == 0) return 0;
        if(s.length() ==1){
            return 1 ;
        }
        int ans = 0 ;
        int i=0 ;
        mp[s[i]]++ ;
        int j=1 ; 
        int cnt = 0 ;
        while(i<s.length() && j<s.length()){
            if(mp.find(s[j]) == mp.end()){
                mp[s[j]]++ ;
                cnt = max(cnt , j-i+1 );
                j++ ;
            }
            else if(mp.find(s[j]) != mp.end()){
            
                cnt = max(cnt , j-i );
                mp.clear() ;
                i++ ;
                mp[s[i]]++ ;
                j=i+1 ;
            }

        }
        return cnt ;

    }
};
