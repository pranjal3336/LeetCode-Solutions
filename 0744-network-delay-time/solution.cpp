class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int , list<pair<int , int>>>adj ;
        for(int i =0 ; i<times.size() ;i++){
            int u = times[i][0] ;
            int v = times[i][1] ;
            int t = times[i][2] ;

            adj[u].push_back({v , t}) ;
        }
        vector<int>dist(n+1 , 1e9) ;

        //priority_queue<pair<int , int>,  vector<pair<int , int>> , greater<pair<int , int>>> pq ;
        set<pair<int , int>>st ;
        dist[k] = 0 ;
        //pq.push({0 , k}) ;
        st.insert({0 ,k}) ;
        while(!st.empty()){
            auto it = *(st.begin()) ;
            st.erase(st.begin()) ;
            int toptime = it.first ;
            int node = it.second ;

            for(auto nbr : adj[node]){
                if(toptime + nbr.second < dist[nbr.first]){
                    auto record = st.find({dist[nbr.first] , nbr.first}) ;
                    if(record != st.end()){
                        st.erase(record) ;
                    }
                    dist[nbr.first] = toptime + nbr.second ;
                    st.insert({dist[nbr.first] , nbr.first}) ;
                }
            }
        }

        int maxi = INT_MIN ;
        for(int i =1 ; i<=n ; i++){
            maxi = max(maxi  , dist[i]) ;
        }

        if(maxi == 1e9){
            return -1 ;
        }

        return maxi ;

    }
};
