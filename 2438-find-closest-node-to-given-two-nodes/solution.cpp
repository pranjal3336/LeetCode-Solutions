class Solution {
public:
    void dfs(int u , vector<int>&dist , vector<bool>&vis , vector<int>& edges ){
        if(u != -1){
            vis[u] = true ;

            int v = edges[u] ;

            if(v != -1 && !vis[v]){
                dist[v] = dist[u] + 1 ;
                dfs(v , dist , vis , edges) ;
            }
        }
        
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size() ;
        vector<int>dist1(n , INT_MAX) ;
        vector<int>dist2(n , INT_MAX) ;

        vector<bool>vis1(n , false) ;
        vector<bool>vis2(n , false) ;

        dist1[node1] = 0 ;
        dist2[node2] = 0 ;

        dfs(node1 , dist1 , vis1 , edges) ;
        dfs(node2 , dist2 , vis2 , edges) ;

        int minDistance = INT_MAX ;
        int minNode = -1 ;

        for(int i=0 ; i<n ; i++){
            int maxi = max(dist1[i] , dist2[i]) ;

            if(minDistance > maxi){
                minDistance = maxi ;
                minNode = i ;
            }
        }

        return minNode ;
    }
};
