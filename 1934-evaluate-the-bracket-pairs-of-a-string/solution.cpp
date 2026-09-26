class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string , string>mp ;
        for(int i =0 ; i<knowledge.size() ; i++){
            mp[knowledge[i][0]] = knowledge[i][1] ;
        }
        string ans = "" ;
        int i = 0 ;
        int n = s.length() ;
        while(i<n){
            if(s[i] == '('){
                int j = i ;
                while(s[j] != ')'){
                    j++ ;
                }
                if(mp.find(s.substr(i+1 , j-i-1)) != mp.end()){
                    ans+=mp[s.substr(i+1 , j-i-1)] ;
                }
                else{
                    ans+='?' ;
                }
                i = j+1 ;


            }
            else{
                ans+=s[i] ;
                i++ ;
            }
        }
        return ans ;
    }
};
