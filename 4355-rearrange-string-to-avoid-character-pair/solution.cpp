class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        // int j = s.length() -1 ;
        // for(int i=0 ; i<s.length() ; i++){
        //     if(s[i] == x && i<j){
        //         swap(s[i] , s[j]) ;
        //         j-- ;
        //     }
        // }
        // return s ;

        int j = 0 ; 
        
        for(int i=0 ; i<s.length() ; i++){
            if(s[i] == y ){
                swap(s[i] , s[j]) ;
                j++ ;
            }
        }

        return s ;
    }
};
