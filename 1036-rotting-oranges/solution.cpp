class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;

        queue<pair<pair<int ,int> , int>>q ;
        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i,j} , 0}) ;
                    grid[i][j] = 0 ;
                }
            }
        }

        int dr[4] ={-1,1,0,0} ;
        int dc[4] = {0,0,-1,1} ;

        int time = 0 ;

        while(!q.empty()){
            int r = q.front().first.first ;
            int c = q.front().first.second ;
            int t = q.front().second ;

            time = max(time , t) ;

            q.pop() ;

            for(int i =0 ; i<4 ; i++){
                int nbr = r + dr[i] ;
                int nbc = c + dc[i] ;

                if(nbr >=0 && nbr <n && nbc >=0 && nbc <m && grid[nbr][nbc] ==1){
                    grid[nbr][nbc] = 2; 
                    q.push({{nbr , nbc} , t+1}) ;
                }
            }
        }

        for(int i =0 ; i<n ; i++){
            for(int j = 0 ; j<m ; j++){
                if(grid[i][j] == 1){
                   return -1 ;
                }
            }
        }
        return time ;
    }
};
