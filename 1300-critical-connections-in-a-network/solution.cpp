class Solution {
public:
    void dfs(int node , int parent ,int timer , unordered_map<int , bool>&visited  ,unordered_map<int , list<int>>&adj  ,vector<int>&disc ,vector<int> &low , vector<vector<int>>&result ){

        visited[node] = true ;
        disc[node] = low[node] = timer ;
        timer++ ;

        for(auto nbr : adj[node]){
            if(nbr == parent){
                continue ;
            }

            if(!visited[nbr]){
                dfs(nbr , node , timer , visited , adj , disc , low , result) ;
                low[node] = min(low[node] , low[nbr]) ;

                //bridge check kr rhe hai ab 
                if(low[nbr]> disc[node]){
                    vector<int>ans ;
                    ans.push_back(node) ;
                    ans.push_back(nbr) ;
                    result.push_back(ans) ;
                }
            }
            else{
                //back edge wala case yaani nbr yaani jo node check kr rhe voh already visited hai 
                low[node] = min(low[node] , disc[nbr]) ;
            }
        }






    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //bridges in graph wala question hai 
        unordered_map<int , list<int>>adj ;
        for(int i =0 ; i<connections.size() ; i++){
            int u = connections[i][0] ;
            int v = connections[i][1] ;

            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        int timer = 0 ;
        int parent = -1 ;
        unordered_map<int , bool>visited ;
        vector<int>disc(n , -1) ;
        vector<int>low(n , -1) ;
        vector<vector<int>>result ;
        for(int i =0 ; i<n ;i++){
            if(!visited[i]){
                dfs(i , parent ,timer , visited , adj , disc , low , result) ;
            }
        }

        return result ;
    }
};
