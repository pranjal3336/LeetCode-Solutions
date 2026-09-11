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
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>rank(n , 0) ;
        vector<int>parent(n) ;
        for(int i=0 ; i<n ; i++){
            parent[i] = i ;
        }

        //making componensts
        for(auto &it : edges){
            int u = it[0] ;
            int v = it[1] ;
            unionbyrank(u , v , rank , parent) ;
            
        }
        //making map for storing parent(componensts) --> size of componenets 
        unordered_map<long long , long long>mp ;
        for(int i=0 ; i<n ; i++){
            int papaji = findParent(i , parent) ;
            mp[papaji]++ ;
        }

        long long  remain = n ;
        long long res = 0 ;
        for(auto it : mp){
            //int papaji = it.first ;
            long long size = it.second ;
            res += size* (remain - size) ;
            remain = remain - size ;
        }
        return res ;
    }
};
