class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int , list<pair<int , int>>>adj ;
        for(int i =0 ; i<flights.size() ; i++){
            int u = flights[i][0] ;
            int v = flights[i][1] ;
            int w = flights[i][2] ;

            adj[u].push_back({v , w}) ;
        }

        queue<pair<int , pair<int , int>>>q ;//yha normal queue se kaam chl jayga kyonki stops+1 hi ho rha hai har baar constant change hai isliye and dynamic change hota toh priority queue lete 

        vector<int>dist(n , 1e9) ;
        dist[src] = 0 ;
        q.push({0 , {src , 0}}) ;// hum {stops , {node , distance/cost}} le rhe hai 
        //bas iss question mai hum stops ke according top le rhe hai distace ko second priority lenge 
        while(!q.empty()){
            auto it =  q.front() ;
            q.pop() ;
  
            int stops = it.first ;
            int node = it.second.first ;
            int cost = it.second.second ;

            if(stops>k){
                continue ;
            }
            for(auto nbr : adj[node]){
                if(cost + nbr.second < dist[nbr.first] && stops<=k){
                    dist[nbr.first] = cost + nbr.second;
                    q.push({stops+1 , {nbr.first , dist[nbr.first]}}) ;
                }
            }
        }
        //agr distance vector mai dst ki value change hi nhi hui toh hum -1 return krenge vrna dist[dst] return krenge 
        if(dist[dst] == 1e9){
            return -1 ;
        }
        return dist[dst] ;
    }
};
