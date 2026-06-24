
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        unordered_map<int , list<pair<int , int>>>adj ;
        for(int i =0 ; i<roads.size() ;i++){
            int u = roads[i][0] ;
            int v = roads[i][1] ;
            int t = roads[i][2] ;

            adj[u].push_back({v , t}) ;
            adj[v].push_back({u , t}) ;

        }
        vector<long long>dist(n , 1e18) ;
        vector<long long >ways(n , 0) ; // yeh vector no of shortest ways to reach i index store krega 
        ways[0] = 1 ;//khud src tk 1 way hi hai 
        
        set<pair<long long , int>>st ;//format {time , node}
        dist[0] = 0 ;
        
        st.insert({0 ,0}) ;
        int cnt = 0 ;
        int MOD = 1e9 + 7 ;
        while(!st.empty()){
            auto it = *(st.begin()) ;
            st.erase(st.begin()) ;
            long long  toptime = it.first ;//jo top of set hai uski time ki value 
            int node = it.second ;

            for(auto nbr : adj[node]){
                // CASE 1: Agar hume ek STRICTLY SHORTER path milta hai nbr tak pahunchne ka
                if(toptime + nbr.second < dist[nbr.first]){
                    
                    // Set mein purani (aur zyada time wali) entry dhoondo
                    auto record = st.find({dist[nbr.first] , nbr.first}) ;
                    
                    // Agar purani entry mili, toh usko set se delete kar do
                    if(record != st.end()){
                        st.erase(record) ;
                    }
                    
                    // Distance array mein naya aur kam time (shortest distance) update karo
                    dist[nbr.first] = toptime + nbr.second ;
                    
                    // SUPER IMPORTANT: Kyunki ek bilkul naya shortest path mila hai, toh pichle 
                    // saare ways bekar ho gaye. Isliye nbr ke ways ko current node ke ways se OVERWRITE kar do.
                    ways[nbr.first] = ways[node] ;
                    
                    // Nayi updated time ki value set mein daal do aage ke nodes explore karne ke liye
                    st.insert({dist[nbr.first] , nbr.first}) ;
                }
                
                // CASE 2: Agar hume ek aur path mila jiska time EXACTLY SAME hai current shortest distance ke
                else if(toptime + nbr.second == dist[nbr.first]){
                    
                    // Iska matlab hume nbr tak pahunchne ka ek 'aur' barabar ka raasta (shortest path) mil gaya hai.
                    // Toh pichle ways mein current node ke ways ADD kar do.
                    // MODULO lagana zaroori hai taaki integer overflow na ho.
                    ways[nbr.first] = (ways[node] + ways[nbr.first]) % MOD ;
                }
            }
        }
        return  ways[n-1] ;


        
    }
};
