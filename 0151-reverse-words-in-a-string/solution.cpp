class Solution {
public:
    string reverseWords(string s) {
        // stringstream ss(s) ;
        
        // string token  ;
        // string res = "" ;
        // while(ss >> token){
        //     if(res.empty()) {
        //         res = token; // Pehla word bina space ke
        //     } else {
        //         res = token + " " + res; // Baaki words ke beech mein space
        //     }
        // }
        // return res ;

        //method 2 using 2 pointers 
        int n = s.length() ;
        reverse(begin(s) , end(s)) ;
        int i = 0 ;
        //l and r ki help se hi word reverse krenge 
        int l = 0 ;
        int r = 0 ;
        while(i<n){
            while( i<n && s[i] != ' '){//i ko jb tk char milega yeh r ko assign krega and aage bdega and r bhi aage bdega
                s[r] = s[i] ;
                i++ ;
                r++ ;
                
            }
            if(l<r){//l __ r ke beech ke word ko hi reverse maarenge single word like l==r hua roh reverse ki jrurat nhi h isliye lgaya hai yeh
                reverse(s.begin()+l , s.begin()+r) ;
                s[r] = ' ';//reverse kre baad ek space ke liye r mai space assign krenge 
                r++ ;//r aage bdao
                l = r ;//l and r same honge next word ke liye 
            }
            i++ ;//i toh purra s traverse kr rh hai yeh yeh increment hota rhega 
        }
        return s.substr(0 , r-1) ;// r-1 tk ki string denge kyonki r and l extra space pr point kr rhe honge 
    }
};
