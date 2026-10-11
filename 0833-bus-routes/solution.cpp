class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target){
            return 0 ;
        }
        
        unordered_map<int , vector<int>>adj ;
        for(int i =0 ; i<routes.size() ; i++){
            for(auto &stop : routes[i]){
                adj[stop].push_back(i) ;
            }
        }

        vector<bool>vis(501 , false) ;
        queue<int>q ;
        for(auto &it : adj[source]){
            vis[it] = true ;
            q.push(it) ;
        }

        int buses = 1 ;//because current hum 1 bus pr toh h hi 

        while(!q.empty()){
             int size = q.size() ;

             while(size--){
                int top = q.front() ;
                q.pop() ;

                for(auto &stop : routes[top]){
                    if(stop == target){
                        return buses ;
                    }

                    for(auto &nextroute : adj[stop]){
                        if(!vis[nextroute]){
                            vis[nextroute] = true ;
                            q.push(nextroute) ;
                        }
                    }
                }
             }
            buses++ ;
        }

        return -1 ;

    }
};
