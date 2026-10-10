class Solution {
public:
    int minInsertions(string s) {
        int cnt = 0 ;
        int result = 0 ;
        int n = s.length() ;
        int i =0 ;
        while(i <n){
            if(s[i] == '('){
                cnt++ ;
                i++ ;
            }
            else{
                if(cnt > 0){
                    cnt-- ;
                }
                else{
                    result++ ;
                }

                if(i<n && s[i+1] == ')'){
                    
                    i+=2 ;
                }
                else{
                    result+=1 ;
                    i++ ;
                }
            }
        }

        return result + cnt*2 ;
    }
};
