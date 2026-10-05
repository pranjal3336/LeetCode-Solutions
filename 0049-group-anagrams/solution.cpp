class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& s) {
        vector<vector<string>>ans ;
        unordered_map<string , vector<string>>mp ;
        int n = s.size() ;

        for(int i=0 ; i<n ; i++){
            string temp = s[i] ;
            sort(begin(temp) , end(temp)) ;
            mp[temp].push_back(s[i]) ;
        }

        for(auto i : mp){
            ans.push_back(i.second) ;
        }

        return ans ;
    }
};
