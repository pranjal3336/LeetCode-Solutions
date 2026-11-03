class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int , int > mp ;//lost mao hai key : player value : count of loses 
        for(auto &i : matches){
            mp[i[1]]++ ;//loose kra hai a
           
        } 

        vector<int>notLost ;
        vector<int>onceLost ;
        int n = matches.size() ;
        for(auto &it : matches){
            if(mp.find(it[0]) == mp.end()){
                notLost.push_back(it[0]) ;
                mp[it[0]] = 2 ;
            }
            if(mp[it[1]] == 1){
                onceLost.push_back(it[1]) ;
            }
        }
        
        sort(begin(notLost) , end(notLost)) ;
        sort(begin(onceLost) , end(onceLost)) ;
        return {notLost , onceLost} ;
    }
};
