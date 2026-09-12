class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int , vector<pair<int ,int>>>adj ;
        for(auto &it : times){
            int u = it[0] ;
            int v = it[1] ;
            int w = it[2] ;

            adj[u].push_back({v,w}) ;//directed graph h yeh 
            
        }

        vector<int>dist(n+1 , INT_MAX) ;

        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>pq ;

        pq.push({0,k}) ;
        dist[k] = 0 ;

        while(!pq.empty()){
            int d = pq.top().first ;
            int node = pq.top().second ;
            pq.pop() ;

            for(auto &nbr : adj[node]){
                int nbrnode = nbr.first ;
                int nbrdis = nbr.second ;

                if(d+ nbrdis < dist[nbrnode]){
                    dist[nbrnode] = d + nbrdis ;
                    pq.push({dist[nbrnode] , nbrnode}) ;
                }
            }
        }
        int maxi = INT_MIN ;
        for(int i =1 ; i<n+1 ; i++){
            maxi = max(maxi , dist[i]) ;
        }

        if(maxi == INT_MAX){
            return -1 ;
        }
        return maxi ;
    }
};
