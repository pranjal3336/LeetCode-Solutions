class Solution {
public:
    int findParent(int node , vector<int>&parent){
        if(parent[node] == node){
            return node ;
        }
        
        return parent[node] = findParent(parent[node] , parent) ;
    }
    
    void unionSet(int u , int v , vector<int>&parent , vector<int>&rank ){
        int ultp_u = findParent(u , parent) ; //hum u ka root parent nikal rhe hai 
        int ultp_v = findParent(v , parent) ;
        
        // Agar dono pehle se same group mein hain, toh kuch mat karo
        if (ultp_u  == ultp_v) {

            return;
        }
        
        
        if(rank[ultp_u ]<rank[ultp_v]){
            parent[ultp_u ] = ultp_v;
        }
        else if(rank[ultp_v]<rank[ultp_u ]){
            parent[ultp_v] = ultp_u ;
        }
        else{
            parent[ultp_u ] = ultp_v ;
            rank[ultp_v]++ ;
        }
        
    
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int m = connections.size() ;
        
        
        vector<int>parent(n) ;
        vector<int>rank(n , 0);
        for(int i=0 ; i<n ; i++){
            parent[i] =i ;
        }

        int extraedges = 0 ;
            for(auto it : connections){
                int u = it[0] ;
                int v = it[1] ;
                if(findParent(u , parent) == findParent(v , parent)){
                    extraedges++ ;
                }
                else{
                    unionSet(it[0] , it[1] , parent , rank) ;
                }
            }
        
        int cnt =0 ;
        for(int i=0 ; i<n ; i++){
            if(parent[i] == i){
                cnt++ ;
            }
        }
        int finalans = cnt - 1;
        if(extraedges>= finalans){
            return finalans ;
        }
        return -1  ;
    }
};
