class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size() ;

        if(n == 0 || grid[0][0] == 1 || grid[n-1][n-1] ==1){
            return -1 ;
        }

        if(n==1 && grid[0][0] != 0){
            return -1 ;
        }
        // queue<pair<int , int>>q ;
        // q.push( {0,0}) ;
        // grid[0][0] = 1;

        // int cnt = 0 ;
        // while(!q.empty()){
        //     int size = q.size() ;//yeh current level ka size bta rha hai queue mai jb tk iss level ke saare node visit nhi krte tb tk cnt++ nhi hoga 
        //     while(size--){
        //         int r = q.front().first ;
        //         int c = q.front().second ;
        //         q.pop() ;
        //         //early exit agr last cell pahuch gye 
        //         if(r == n-1 && c== n-1){
        //             return cnt+1 ;//cnt sirf levels bta rha hai and level 0 se start hote hai and no of cells humesha levels+1 yaani cnt+1 hoga 
        //         }

        //         for(int i = -1 ; i<=1 ; i++){
        //             for(int j = -1 ; j<=1 ; j++){
        //                 int nbrrow = r + i ;
        //                 int nbrcol = c + j ;

        //                 if(nbrrow >= 0 && nbrrow < n && nbrcol >= 0 && nbrcol < n && grid[nbrrow][nbrcol] == 0){
        //                     grid[nbrrow][nbrcol] = 1;
        //                     q.push({nbrrow, nbrcol});
        //                 }
        //             }
        //         }
        //     }
        //     //ab level visit kr liya ab cnt++ krenge ;
        //     cnt++ ;
        // }

        // return -1 ;

        //method 2 using dijkstra 
        vector<vector<int>>dist(n , vector<int>(n , INT_MAX)) ;
        priority_queue<pair<int , pair<int , int>> , vector<pair<int , pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq ;

        pq.push({0 , {0,0}}) ;
        dist[0][0] = 0 ;
        grid[0][0] = 1 ;

        while(!pq.empty()){
                int d = pq.top().first ;
                int r = pq.top().second.first ;
                int c = pq.top().second.second ;
                pq.pop() ;
               
                for(int i = -1 ; i<=1 ; i++){
                    for(int j = -1 ; j<=1 ; j++){
                        int nbrrow = r + i ;
                        int nbrcol = c + j ;

                        if(nbrrow >= 0 && nbrrow < n && nbrcol >= 0 && nbrcol < n && grid[nbrrow][nbrcol] == 0){
                            if(d + 1 < dist[nbrrow][nbrcol]){
                                grid[nbrrow][nbrcol] = 1 ;
                                dist[nbrrow][nbrcol] = d+1 ;
                                pq.push({d+1 , {nbrrow , nbrcol}}) ;
                            }
                        }
                    }
                }
        }
        if(dist[n-1][n-1] != INT_MAX){
            return dist[n-1][n-1] + 1 ;//dist[n-1][n-1] sirf distance(edges) bta rha hai 0,0 se n-1 , n-1 tk but hume no of cells(vertices) btane hai toh voh 1 jyada honge humesha edges yaani distance se 
        }
        return -1 ;

    }
};
