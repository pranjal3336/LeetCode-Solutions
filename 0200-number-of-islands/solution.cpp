class Solution {
public:
    void dfs(int r , int c , vector<vector<char>>& grid , int n , int m){
        grid[r][c] = '0' ;

        int dr[4] ={-1,1,0,0} ;
        int dc[4] = {0,0,-1,1} ;

        for(int i =0 ; i<4 ; i++){
            int nbr = r + dr[i] ;
            int nbc = c + dc[i] ;

            if(nbr >=0 && nbr <n && nbc >=0 && nbc <m && grid[nbr][nbc] == '1'){
                dfs(nbr , nbc , grid , n , m) ;
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        int cnt = 0 ;
        for(int i =0 ; i<n ; i++){
            for(int j =0 ; j<m ; j++){
                if(grid[i][j] == '1'){
                    cnt++ ;
                    dfs(i , j , grid , n , m) ;
                }
            }
        }
        return cnt ;
    }
};
