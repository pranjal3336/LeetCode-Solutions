class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n =mat.size() ;
        int m = mat[0].size() ;
        
        // Iss ques mai BFS lagega kyunki minimum time nikalna hai and level order traversal krna hai 
        // Visited array track karega ki kaunsa orange rot ho chuka hai (true)
        vector<vector<bool>> visited(n , vector<bool>(m , false)) ;
        
        // Queue format: {{row, col}, current_time}
        queue<pair<pair<int , int> , int>> q ;

        vector<vector<int>>dist(n , vector<int>(m , 0)) ;//hume matrix return krna hai 

        // STEP 1: Multi-source BFS Initialization
        // Pura mat traverse karke saare 0  ko queue me daalo.
        // inn sbka distance 0 hoga kyunki yeh khud hi  0 hai 
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(mat[i][j] == 0){
                    q.push({{i , j} , 0}) ;
                    visited[i][j] = true ; // Inko pehle hi visited mark kar do
                }
            }
        }
        
        
        // 4-directional movement ke liye arrays (Up, Left, Down, Right)
        int drow[] = {0 , -1 , 0 , 1} ;
        int dcol[] = {-1 , 0 , 1 , 0} ;
         
        
        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int steps = q.front().second ;
            q.pop() ;

            
            dist[row][col] = steps ;
            
          
            for(int i = 0 ; i < 4 ; i++){
               
                int nbrrow = row + drow[i] ;
                int nbrcol = col + dcol[i] ;

                if(nbrrow >= 0 && nbrrow < n && nbrcol >= 0 && nbrcol < m &&  !visited[nbrrow][nbrcol]){
                    
                    
                    q.push({{nbrrow , nbrcol} , steps + 1}) ;
                    visited[nbrrow][nbrcol] = true ;
                }   
            }
        }

        
        return dist ;
    }
};
