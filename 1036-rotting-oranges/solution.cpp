class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() ;
        int  n = grid[0].size() ;

        queue<pair<pair<int , int> , int>>q ;

        for(int i=0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0}) ;
                    grid[i][j] = -1 ;
                }
            }
        }
        
        int timer = 0 ;
        int dr[4] = {-1 , 1 , 0 ,0} ;
        int dc[4] = {0,0,-1,1} ;

        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int t = q.front().second ;
            q.pop() ;

            timer = max(t , timer) ;

            for(int i=0 ; i<4 ; i++){
                int nrow = row + dr[i] ;
                int ncol = col + dc[i] ;

                if(nrow >=0 && nrow < m && ncol>= 0 && ncol <n && grid[nrow][ncol] ==1){
                    q.push({{nrow , ncol} , t+1}) ;
                    grid[nrow][ncol] = -1 ;
                }
            }
        }

        for(int i=0 ; i<m ; i++){
            for(int j =0 ; j<n ; j++){
                if(grid[i][j] ==1){
                    return -1 ;
                }
            }
        }

        return timer ;
    }
};
