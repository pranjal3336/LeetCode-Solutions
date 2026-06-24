class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size() ;
        int m = heights[0].size() ;

        // Distance array to store the minimum effort required to reach each cell.
        // Starting mein sabhi cells ko infinity (1e9) set kiya hai.
        vector<vector<int>>dist(n , vector<int>(m , 1e9)) ;

        // Min-heap priority queue Dijkstra's algorithm ke implementation ke liye.
        // Format: {effort, {row, col}}. 
        // Min-heap ensure karta hai ki sabse kam effort wala path pehle process ho.
        priority_queue<pair< int , pair<int , int> > , vector<pair< int , pair<int , int> >> , greater<pair< int , pair<int , int> >>>pq ;

        // Source cell (0,0) ko queue mein push kar rahe hain with 0 effort.
        pq.push({0 , {0,0} }) ;
        dist[0][0] = 0 ; // Source se source tak ka effort hamesha 0 hota hai.

        // 4 directions (Up, Left, Down, Right) mein move karne ke liye arrays.
        // Yeh standard BFS/Dijkstra matrix traversal technique hai.
        int drow[] = {-1 , 0 , 1 , 0} ; 
        int dcol[] = {0 , -1 , 0 , 1} ; 

        while(! pq.empty()){
            // Sabse minimum effort wale current cell ko extract kar rahe hain.
            auto  it = pq.top() ;
            pq.pop() ;
            
            int d = it.first ;               // Current cell tak aane ka maximum effort
            int row = it.second.first ;      // Current row index
            int col = it.second.second ;     // Current col index
        
            // Early Exit: Agar hum destination (bottom-right) pe pohoch gaye, 
            // toh wahi minimum effort hoga kyunki queue humesha pehle minimum ko top pe rakhti hai.
            if(row == n-1 && col == m-1){
                return d ;
            }
            
            // Current cell ke 4 padosi (adjacent) cells ko check kar rahe hain.
            for(int i =0 ; i<4 ; i++){
                int nbrrow = row + drow[i] ;
                int nbrcol = col + dcol[i] ;
                
                // Boundary check: Yeh ensure karta hai ki hum grid ke bahar (invalid index) move na karein.
                if(nbrrow >=0 && nbrrow<n && nbrcol>=0 && nbrcol <m ){

                    // Naye cell tak pohochne ka naya effort nikal rahe hain.
                    // Problem statement ke according: yeh ab tak ka max effort 'd' aur next step ke jump (abs diff) ka maximum hoga.
                    int neweffort = max(abs(heights[nbrrow][nbrcol] - heights[row][col]) , d) ;
                    
                    // Relaxation Condition (Optimization step):
                    // Yeh condition 2 kaam kr rhi hai: 
                    // 1. Ek toh agr hum phli baar value daal rhe hai like 1 < infinity hai toh 1 kr denge uss cell main.
                    // 2. Dubara phle visited kr chuke cell pr jaane se rok rhi hai (unless hume koi sasta path mile). Isse TLE (Time Limit Exceeded) nahi aata.
                    if(neweffort < dist[nbrrow][nbrcol]){
                        dist[nbrrow][nbrcol] = neweffort ;         // Behtar effort mila toh array update karo
                        pq.push({ neweffort , {nbrrow , nbrcol}}); // Naye path ko explore karne ke liye queue mein daalo
                    }
                    
                }
            }
        }

        return 0 ; // Fallback return (halanki flow yahan nahi pahuchega constraints ke according) yeh bas extra likha hai taaki code chl jaaye 

    }
};
