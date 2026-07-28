class Solution {
public:
    string removeKdigits(string num, int k) {
        // //stack<char>st ;//yha mai string bhi le skta tha like string result ="" kyonki string bhi stack ki trh hi hoti hai
        
        // for(int i=0 ; i<num.length() ; i++){
        //     char curr = num[i] ;
        //     while(!st.empty() && k>0 &&  st.top() > curr){
        //         st.pop() ;
        //         k-- ;
        //     }
        //     if(curr != '0' || st.size() >0){
        //         st.push(curr) ;
        //     }
        // }

        // while(!st.empty() && k>0){
        //     st.pop() ;
        //     k-- ;
        // }

        // string ans = "" ;
        // while(!st.empty()){
        //     ans+=st.top() ;
        //     st.pop() ;
        // }

        // reverse(ans.begin() , ans.end()) ;
        // if(ans == ""){
        //     return "0" ;
        // }
        // return ans ;

        //method 2 same hai bas string use kr rha hu 

        //stack<char>st ;//yha mai string bhi le skta tha like string result ="" kyonki string bhi stack ki trh hi hoti hai
        string result = "" ;

        for(int i=0 ; i<num.length() ; i++){
            char curr = num[i] ;
            while(result.length() >0  && k>0 &&  result.back() > curr){
                result.pop_back() ;
                k-- ;
            }
            if(curr != '0' || result.length() >0){
                result.push_back(curr) ;
            }
        }

        while(result.length()>0 && k>0){
            result.pop_back() ;
            k-- ;
        }

        
        if(result == ""){
            return "0" ;
        }
        return result  ;
    }
};
