class Solution {
public:
// bool isValid(string &s){
//     stack<char>st ;
//     for(char &ch :s){
//         if(ch == '('){
//             st.push(ch) ;
//         }
//         else if(ch == ')'){
//             if(!st.empty() && st.top() == '('){
//                 st.pop() ;
//             }
//             else{
//                 st.push(ch) ;
//             }
//         }
//     }

//     if(st.empty()){
//         return true ;
//     }
//     return false ;
// }

//valid parenthesis ka ek au r method h using counter value 
    bool isValid(string &s){
        int cnt = 0 ;
        for(char &ch :s){
            if(ch == '('){
                cnt++ ;
            }
            else{
                cnt-- ;
            }
            if(cnt <0){//agr khi beech mai cnt <0 yaani negative hua toh yhi invalid str mil gyi thi ())( yha +1-1-1+1=0 aa rha hai pr yeh valid nhi h toh jaise hi +1-1-1 yaani cnt = -1 hua toh false return kr denge 
                return false ;
            }
        }

        return cnt == 0 ;//agr cnt=0 hua toh true vrna false ;
    }
    // void solve(int n , int i  , string&curr , vector<string>&ans){
    //     if(i== 2*n){//konki agr n =2 hai toh string mai 2 open and 2 close parenthesis aayenge yaani jb i == 2*n hoga tb base case reach hua hai 
    //         if(isValid(curr)){
    //             ans.push_back(curr) ;
    //         }
    //         return ;
    //     }

    //     curr.push_back('(') ;
    //     solve(n , i+1 , curr , ans) ;
    //     curr.pop_back() ;
    //     curr.push_back(')') ;
    //     solve(n , i+1 , curr , ans) ;
    //     curr.pop_back() ;
    // }
    //yha hume isvalid function ki jrurat nhi hai kyonki hum valid string hi bna rhe hai open and close parenthesis ka track rkhkr 
    void solve(int n , int i  , string&curr , vector<string>&ans , int open , int close){
        if(i== 2*n){//konki agr n =2 hai toh string mai 2 open and 2 close parenthesis aayenge yaani jb i == 2*n hoga tb base case reach hua hai 
            ans.push_back(curr) ;
            return ;
        }

        if(open < n){//open humesha <n hone chahiye jbhi add krenge 
            curr.push_back('(') ;
            solve(n , i+1 , curr , ans , open+1 , close) ;
            curr.pop_back() ;
        }
        
        if(close < open){//close humesha < open hone chahiye agr close jyada hue toh valid nhi hogi ad usse consider bhi nhi krega yeh function 
            curr.push_back(')') ;
            solve(n , i+1 , curr , ans , open , close+1) ;
            curr.pop_back() ;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        string curr = "" ;
        int open =0 , close = 0 ;
        solve(n , 0 , curr  , ans , open , close ) ;
        return ans ;
    }
};
