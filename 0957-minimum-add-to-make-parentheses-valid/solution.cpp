class Solution {
public:
    int minAddToMakeValid(string s) {
       //method 1 using stack 
        // int n = s.length() ;
        // stack<char>st ;
        // for(int i=0 ; i<n ; i++){
        //     if(!st.empty()){
        //         if(s[i] == '('){
        //             st.push(s[i]) ;
        //         }
        //         else{
        //             if(st.top() == '('){
        //                 st.pop() ;
        //             }
        //             else{
        //                 st.push(s[i]) ;
        //             }
        //         }
        //     }
        //     else{
        //         st.push(s[i]) ;
        //     }
        // }
        // return st.size();


        //method 2 without stack 
        int n = s.length() ;
        int size = 0 ;
        int openNeeded = 0 ;

        for(char ch : s){
            if(ch == '('){
                size++ ;
            }
            else{
                if(size>0){
                    size-- ;
                }
                else{
                    openNeeded++ ;
                }
            }
        }

        return openNeeded+size ;

    }
};
