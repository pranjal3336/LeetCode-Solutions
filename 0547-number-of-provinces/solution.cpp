class Solution {
public:
    // void dfs(int node ,unordered_map<int , bool> &vis , vector<vector<int>>& isConnected , int n){
    //     vis[node] = true ; 

    //     for(int j= 0 ; j< n ; j++){
    //         if(!vis[j] && isConnected[node][j] == 1 && node != j){//khud ko toh 1 hi given hai yaani diagonal element nhi ho chahiye 
    //             dfs(j , vis , isConnected , n) ;
    //         }
    //     }
    // }

    int findParent(vector<int>&parent , int node){
        if(parent[node] == node){
            return node ;
        }

        return parent[node] = findParent(parent , parent[node]) ;
    }

    void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
        u = findParent(parent , u) ;
        v = findParent(parent , v) ;

        if(u==v){
            return ;
        }
        if(rank[u]<rank[v]){
            parent[u] = v ;
        }
        else if(rank[u]>rank[v]){
            parent[v] = u ;
        }
        else{
            parent[u] = v ;
            rank[v]++ ;
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // unordered_map<int , bool>vis ;
         int n = isConnected.size() ;
        // int cnt = 0 ;
        // for(int i=0 ; i<n ; i++){
        //     if(!vis[i]){
        //         dfs(i , vis , isConnected , n) ;
        //         cnt++ ;
        //     }
        // }

        // return cnt ;

        vector<int>parent(n) ;
        for(int i=0 ; i<n ; i++){
            parent[i] = i ;
        }
        vector<int>rank(n, 0) ;

        for(int i=0 ; i<n ; i++){
            for(int j =0 ; j<n ; j++){
                if(isConnected[i][j] == 1 && i!= j){
                    unionSet(i , j , parent , rank) ;
                }
            }
        }
        int cnt = 0 ;
        for(int i=0 ; i<n ; i++){
            if(parent[i] == i){
                cnt++ ;
            }
        }
        return cnt ;




    }
};
