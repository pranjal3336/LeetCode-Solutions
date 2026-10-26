class Solution {
public:
    int dr[4] = {-1,1,0,0} ;
    int dc[4] = {0,0,-1,1} ;
    void dfs(int r , int c , int m , int n , vector<vector<int>>& grid , vector<vector<bool>>&vis , long long &sum){
        sum += grid[r][c] ;
        vis[r][c] = true ;

        for(int i=0 ; i<4 ; i++){
            int nr = r + dr[i] ;
            int nc = c + dc[i] ;

            if(nr >=0 && nr <m && nc >=0 && nc <n && !vis[nr][nc] && grid[nr][nc] != 0){
                dfs(nr , nc , m , n, grid , vis , sum) ;
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size() ;
        int n = grid[0].size() ;

        int ans = 0 ;
        vector<vector<bool>>vis(m , vector<bool>(n , false)) ;
        for(int i =0 ; i<m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(!vis[i][j] && grid[i][j] != 0){
                    long long  sum = 0 ;
                    dfs(i , j ,m , n,  grid , vis , sum) ;
                    if(sum%k == 0){
                        ans++ ;
                    }
                }
            }
        }

        return ans ;

    }
};
