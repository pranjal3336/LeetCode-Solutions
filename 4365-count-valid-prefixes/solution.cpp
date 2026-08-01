class Solution {
public:
    int countValidPrefixes(string s) {
        int n = s.length() ;
        int ans = 0 ;
        int cnt0 = 0 ;
        int cnt1 = 0 ;
        for(int i=0 ; i<n ; i++){
            
            if(s[i] == '0'){
                cnt0 ++ ;
            }
            else{
                cnt1++ ;
            }

            if(abs(cnt1 - cnt0) <=1){
                ans++ ;
            }
        }

        return ans ;
    }
};
