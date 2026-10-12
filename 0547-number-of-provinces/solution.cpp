class Solution {
public:
    void dfs(int i , vector<vector<int>>& isConnected , vector<bool>&vis , int n){
        vis[i] = true ;

        for(int j=0 ; j<n ; j++){
            if(i!= j && isConnected[i][j] == 1 && !vis[j]){
                dfs(j , isConnected , vis , n) ;
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size() ;
        int cnt =0 ;
        vector<bool>vis(n , false) ;
        for(int i = 0 ; i<n ; i++){
            if(!vis[i]){
                dfs(i , isConnected , vis , n) ;
                cnt++ ;
            }
            
        }

        return cnt ;
    }
};
