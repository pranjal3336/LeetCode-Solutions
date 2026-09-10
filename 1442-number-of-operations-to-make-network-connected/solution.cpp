class Solution {
public:
    int findParent(int i , vector<int>&parent){
        if(i == parent[i]){
            return i ;
        }

        return parent[i] = findParent(parent[i] , parent) ;
    }

    void unionbyrank(int u , int v , vector<int>&rank , vector<int>&parent){
        int u_par = findParent(u , parent) ;
        int v_par = findParent(v , parent) ;

        if(u_par == v_par){
            return ;
        }

        if(rank[u_par] < rank[v_par]){
            parent[u_par] = parent[v_par] ;
        }
        else if(rank[u_par] > rank[v_par]){
            parent[v_par] = parent[u_par] ;
        }
        else{
            parent[u_par] = parent[v_par] ;
            rank[v_par]++ ;
        }

    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int>rank(n , 0) ;
        vector<int>parent(n) ;
        for(int i=0 ; i<n ; i++){
            parent[i] = i ;
        }
        int e = connections.size() ;
        if(e < n-1 ){
            return -1 ;
        }

        for(auto &it : connections){
            int u = it[0] ;
            int v = it[1] ;

            if(findParent(u , parent) != findParent(v , parent)){
                n-- ;
                unionbyrank(u , v , rank , parent) ;
            }
        }

        return n-1 ;
    }
};
