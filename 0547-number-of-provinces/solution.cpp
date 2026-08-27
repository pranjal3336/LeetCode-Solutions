class Solution {
public:
    void dfs(int node ,  vector<vector<int>>& isConnected , vector<bool>&vis , int n ){
        vis[node] = true ;

        for(int i =0 ; i<n ; i++ ){
            if(!vis[i] && isConnected[node][i] == 1 && i!= node){
                dfs(i , isConnected , vis , n) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int cnt = 0 ;
        int n = isConnected.size() ;
        vector<bool>vis(n , false) ;
        for(int i=0 ; i<n ; i++){
           if(!vis[i]){
            dfs(i , isConnected , vis , n) ;
            cnt++ ;
           }
        }

        return cnt ;
    }
};
