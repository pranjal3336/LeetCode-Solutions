class Solution {
public:
    int dr[4] = {-1,1,0,0} ;
    int dc[4] = {0,0,-1,1} ;
    void dfs(int r , int c ,int n , int m ,  vector<vector<int>>& grid ,vector<vector<int>>&vis ){
        vis[r][c] = true ;

        for(int i =0 ; i<4 ; i++){
            int nr = r + dr[i] ;
            int nc = c + dc[i] ;

            if(nr >=0 && nr <n-1 && nc >=0 && nc < m-1 && grid[nr][nc] == 0 && !vis[nr][nc] ){
                dfs(nr , nc , n , m , grid , vis) ;
            }

        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size()  ;
        int m = grid[0].size() ;
        int ans  = 0 ;
        vector<vector<int>>vis(n , vector<int>(m , false)) ;
        for(int i : {0, n-1}){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 0){
                    dfs(i , j , n , m , grid , vis) ;
                }
            }
        }

        for(int j : {0, m-1}){
            for(int i = 0 ; i<n ; i++){
                if(grid[i][j] == 0){
                    dfs(i , j , n , m , grid , vis) ; 
                }
            }
        }
        for(int i = 0 ; i<n ; i++){
            for(int j= 0 ; j<m ; j++){
                if(grid[i][j] == 0 && !vis[i][j]){
                    dfs(i , j , n , m,  grid , vis) ;
                    ans++ ;
                }
            }
        }

        return ans ;
    }
};
