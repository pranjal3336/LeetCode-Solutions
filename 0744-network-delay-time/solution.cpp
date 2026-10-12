class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int , vector<pair<int , int>>>adj ;

        for(auto &it : times){
            int u = it[0] ;
            int v = it[1] ;
            int w = it[2] ;

            adj[u].push_back({v,w}) ;
        }

        vector<int>dist(n+1 , INT_MAX) ;
        priority_queue<pair<int , int> , vector<pair<int , int>> , greater<pair<int , int>>>q ;
        q.push({0,k}) ;
        dist[k] = 0 ;

        while(!q.empty()){
            int d = q.top().first ;
            int node = q.top().second ;
            q.pop() ;

            for(auto &nbr : adj[node]){
                int nbrnode = nbr.first ;
                int nbrd = nbr.second ;

                if(d+nbrd < dist[nbrnode]){
                    dist[nbrnode] = d + nbrd ;
                    q.push({dist[nbrnode] , nbrnode}) ;
                }

            }
        }

        int maxi = INT_MIN ;

        for(int i=1 ; i<n+1 ; i++){
            maxi = max(maxi , dist[i]) ;
        }

        if(maxi == INT_MAX){
            return -1 ;
        }

        return maxi ;
    }
};
