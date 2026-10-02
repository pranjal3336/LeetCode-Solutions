class Solution {
public:
    void solve(int n , int i , string curr ,vector<string>&ans , int open , int close){
        if(i == 2*n){
            ans.push_back(curr) ;
            return ;
        }

        if(open <n){
            curr.push_back('(') ;
            solve(n , i+1 , curr , ans , open+1 , close) ;
            curr.pop_back() ;
        }

        if(close < open){
            curr.push_back(')') ;
            solve(n , i+1 , curr , ans , open , close+1) ;
            curr.pop_back() ;
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans ;
        int open = 0 ;
        int close = 0 ;
        string curr ;
        solve(n ,0 ,  curr , ans , open , close) ;

        return ans ;

    }
};
