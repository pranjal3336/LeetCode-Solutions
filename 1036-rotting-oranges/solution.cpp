class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size() ;
       int m = grid[0].size() ;

       queue<pair<pair<int ,int> , int>>q ;
        vector<vector<bool>>vis(n , vector<bool>(m , false)) ;
       for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(grid[i][j] == 2){
                q.push({{i,j} , 0}) ;
                vis[i][j] = true ;
            }
        }
       }

       int drow[4] = {0 , -1 , 0 , 1} ;
       int dcol[4] = {-1 , 0 , 1 , 0} ;

       int timer = 0 ;

       while(!q.empty()){

            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int t= q.front().second ;
            q.pop() ;

            timer = max(timer , t) ;

            for(int i=0 ; i<4 ; i++){
                int nbrrow = row+ drow[i] ;
                int nbrcol = col + dcol[i] ;

                if(nbrrow >=0 && nbrrow<n && nbrcol>=0 && nbrcol<m && !vis[nbrrow][nbrcol] && grid[nbrrow][nbrcol] ==1){
                    q.push({{nbrrow , nbrcol} , t+1}) ;
                    vis[nbrrow][nbrcol] = true ;

                }

            }

       }

       for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(vis[i][j] == false  && grid[i][j]==1){
                return -1 ;
            }
        }
       }

       return timer ;
    }
};
