class Solution {
public:
    void solve(int i , int n , string &curr , string &s ,  unordered_set<string>&ans , int cnt , int &maxlen){
        if(cnt <0){
            return ;
        }
        
        if(i==n){
            if(cnt == 0){
                if(curr.length() >maxlen){
                    maxlen = curr.length() ;
                    ans.clear() ;
                }
                if(curr.length() == maxlen){
                    ans.insert(curr) ;
                }
            }

            return ;
        }

        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]) ;
            solve(i+1 , n , curr , s , ans , cnt , maxlen) ;
            curr.pop_back() ;
            return ;
        }

        curr.push_back(s[i]);
        solve(i+1 , n , curr , s , ans , cnt+(s[i] =='(' ? 1:-1) , maxlen) ;
        curr.pop_back() ;
        solve(i+1 , n , curr , s , ans , cnt , maxlen) ;


    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.length() ;
        string temp ;
        unordered_set<string>ans ;
        int maxlen = 0 ;
        int cnt = 0 ;
        solve(0 , n , temp , s , ans , cnt , maxlen) ;
        
        return vector<string>(begin(ans) , end(ans)) ;
    }
};
