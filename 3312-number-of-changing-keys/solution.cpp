class Solution {
public:
    int countKeyChanges(string s) {
        int n = s.length() ;
        if(n ==1){
            return 0 ;
        }
       int i =0 ;
       int j = 1 ;
       int cnt = 0 ;
       while(j<n){
            if(tolower(s[i]) != tolower(s[j])){
                cnt++ ;
            }
            i++ ;
            j++ ;
       }
       return cnt ;
    }
};
