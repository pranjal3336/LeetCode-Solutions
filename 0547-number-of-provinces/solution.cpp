class Solution {
public:
    // int findParent(int node , vector<int>&parent){
    //     if(parent[node] == node){
    //         return node ;
    //     }
        
    //     return parent[node] = findParent(parent[node] , parent) ;
    // }
    
    // void unionSet(int u , int v , vector<int>&parent , vector<int>&rank){
    //     int ultp_u = findParent(u , parent) ; //hum u ka root parent nikal rhe hai 
    //     int ultp_v = findParent(v , parent) ;
        
    //     // Agar dono pehle se same group mein hain, toh kuch mat karo
    //     if (ultp_u  == ultp_v) {
    //         return;
    //     }
        
        
    //     if(rank[ultp_u ]<rank[ultp_v]){
    //         parent[ultp_u ] = ultp_v;
    //     }
    //     else if(rank[ultp_v]<rank[ultp_u ]){
    //         parent[ultp_v] = ultp_u ;
    //     }
    //     else{
    //         parent[ultp_u ] = ultp_v ;
    //         rank[ultp_v]++ ;
    //     }
        
    
    // }

    void dfs(vector<vector<int>>& isConnected , unordered_map<int , bool> &vis , int node , int n){
        vis[node] = true ;

        for(int j=0 ; j<n ; j++){
            if(isConnected[node][j] == 1 && j != node && !vis[j]){
                dfs(isConnected , vis , j , n) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        //hum iss question ko disjoint set ka use krke bhi kr skte hai mtlb jo connected component honge unke ultimate parent same honge yaani hume unique root parent count krne honge bs 
        // int n = isConnected.size() ;
        // //hume ek trh se adjacency matrix hi given hai 
        // vector<int>parent(n) ;
        // vector<int>rank(n , 0);
        // for(int i=0 ; i<n ; i++){
        //     parent[i] =i ;
        // }

        // for(int i=0 ; i<n ; i++){
        //    for(int j=0 ; j<n ; j++){
        //         if(isConnected[i][j] ==1 && i!=j){
        //             unionSet(i , j , parent , rank) ;
        //         }
        //    }
        // }
        // int cnt =0 ;
        // for(int i=0 ; i<n ; i++){
        //     if(parent[i] == i){
        //         cnt++ ;
        //     }
        // }
        // return cnt ;


        int n = isConnected.size() ;
        unordered_map<int , bool> vis ;
        int cnt =0 ;
        for(int i=0; i<n ; i++){
            if(!vis[i]){
                dfs(isConnected , vis , i , n) ;
                cnt++ ;
            }
        }
        return cnt ;
    }
};
