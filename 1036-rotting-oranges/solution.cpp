class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size() ;
        int m = grid[0].size() ;
        
        // Iss ques mai BFS lagega kyunki minimum time nikalna hai and level order traversal krna hai 
        // Visited array track karega ki kaunsa orange rot ho chuka hai (true)
        vector<vector<bool>> visited(n , vector<bool>(m , false)) ;
        
        // Queue format: {{row, col}, current_time}
        queue<pair<pair<int , int> , int>> q ;

        // STEP 1: Multi-source BFS Initialization
        // Pura grid traverse karke saare initially rotten oranges (2) ko queue me daalo.
        // Ye sab ek sath (time = 0 par) aas-paas ke fresh oranges ko rot karna shuru karenge.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push({{i , j} , 0}) ;
                    visited[i][j] = true ; // Inko pehle hi visited mark kar do
                }
            }
        }
        
        int timer = 0 ;
        
        // 4-directional movement ke liye arrays (Up, Left, Down, Right)
        int drow[] = {0 , -1 , 0 , 1} ;
        int dcol[] = {-1 , 0 , 1 , 0} ;
         
        // STEP 2: Level-Order Traversal (Process minute by minute)
        while(!q.empty()){
            int row = q.front().first.first ;
            int col = q.front().first.second ;
            int t = q.front().second ;
            q.pop() ;

            // Har baar maximum time ko update karo, kyunki answer total time taken hoga
            timer = max(timer , t) ;
            
            // Current rotten orange ke 4 neighbors check karo
            for(int i = 0 ; i < 4 ; i++){
               
                int nbrrow = row + drow[i] ;
                int nbrcol = col + dcol[i] ;

                // VALIDATION: Boundary check, grid cell me fresh orange (1) hona chahiye, 
                // aur wo pehle se visited (rotted) nahi hona chahiye.
                if(nbrrow >= 0 && nbrrow < n && nbrcol >= 0 && nbrcol < m && grid[nbrrow][nbrcol] == 1 && !visited[nbrrow][nbrcol]){
                    
                    // Naya rotted orange queue me jayega with time + 1
                    q.push({{nbrrow , nbrcol} , t + 1}) ;
                    visited[nbrrow][nbrcol] = true ;
                }   
            }
        }

        // STEP 3: Final Unreachable Check
        // Note: Agar disconnected component hua toh wo kabhi rotten nahi hoga.
        // Pura BFS khatam hone ke baad check karo kya koi fresh orange (1) bach gaya jo visited nahi hai.
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(!visited[i][j]  && grid[i][j] == 1){
                   return -1 ; // Ek bhi fresh orange bach gaya toh -1 return karna hai
                }
            }
        }

        // Agar saare fresh oranges rot ho gaye, toh total time return kar do
        return timer ;
    }
};
