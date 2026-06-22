class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        vector<vector<int>>dist(n , vector<int>(m , 1e9)) ;
        queue<pair<pair<int , int> , int >>q ;
        
        if(grid[0][0] == 1 || grid[n-1][m-1] ==1){
            return  -1 ;
        }
        //edge case if [[0]] hi ho toh iske nbrs humesha bahr jaayenge and kbhi condition nhi chlegi nbrrow == n-1 && nbrcol == m-1 yeh wali isliye isse alg se handle krna pdega 
        if(n == 1 && m ==1 && grid[0][0] == 0){
            return 1 ;
        }
            int ans  = -1 ; 
            q.push({{0, 0} , 1}) ;
            dist[0][0] = 0 ;
            while(!q.empty()){
                int row = q.front().first.first ;
                int col = q.front().first.second ;
                int d = q.front().second ;
                q.pop() ;


                for(int drow = -1 ; drow<=1 ; drow++){
                    for(int dcol = -1 ; dcol<=1 ; dcol++){
                        int nbrrow = row + drow ;
                        int nbrcol = col + dcol ;
                        if (nbrrow>=0 && nbrrow <n && nbrcol>=0 && nbrcol <m && grid[nbrrow][nbrcol]==0 && 1 + d <dist[nbrrow][nbrcol]){
                            dist[nbrrow][nbrcol] = 1 + d ;
                            if(nbrrow == n-1 && nbrcol == m-1){
                                return  ans = 1+d ;
                            
                            }
                            q.push({{nbrrow , nbrcol} , d+1}) ;
                        }
                    } 
                }
            }
         
        return ans ;
        
    }
};
