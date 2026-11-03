class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int , int>mp ;
        for(int &i :arr){
            mp[i]++ ;
        }
        set<int>st ;

        for(auto it:mp){
            st.insert(it.second) ;
        }

        return st.size() == mp.size() ;
    }
};
