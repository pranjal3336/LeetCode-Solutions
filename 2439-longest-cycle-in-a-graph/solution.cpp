class Solution {
public:
    int res = -1 ;
    void dfs(int u ,vector<int>& edges , vector<bool>&vis ,vector<bool>&inRecursion ,vector<int>&count ){
        
        vis[u] = true ;
        inRecursion[u] = true ;

        int v = edges[u] ;

        if(v != -1 && !vis[v]){
            count[v] = count[u] + 1 ;
            dfs(v , edges , vis , inRecursion , count) ;
        }
        else if(v != -1 && inRecursion[v] == true){
            res = max(res , count[u]-count[v]+1) ;
        }

        inRecursion[u] = false ;

    }
    int longestCycle(vector<int>& edges) {
        int n = edges.size() ;

        vector<bool>vis(n , false) ;
        vector<bool>inRecursion(n , false) ;

        vector<int>count(n , false) ;

        for(int i=0 ; i<n ; i++){
            dfs(i ,edges , vis , inRecursion , count) ;
        }

        return res ;
    }
};
