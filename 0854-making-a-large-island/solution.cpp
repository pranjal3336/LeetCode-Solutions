class Solution {
public:
    int findParent(int node , vector<int>&parent){
        if(parent[node] == node){
            return node ;
        }

        return parent[node] = findParent(parent[node] , parent) ;
    }

    void unionBysize(int u , int v , vector<int>&parent , vector<int>&size ){
        u = findParent(u , parent) ;
        v = findParent(v , parent) ;
        if(u == v) return;
        if(size[u]<size[v]){
            parent[u] = v ;
            size[v]+=size[u] ;
        }
        else{
            parent[v] = u;
            size[u] += size[v] ;
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = m * m; // Total cells, hum har 2D cell ko ek 1D integer index de rahe hain

        vector<int> parent(n);
        vector<int> size(n, 1); // Shuru mein har node (island) ka size 1 hoga
         
        // DSU Initialization
        for(int i = 0; i < n; i++) parent[i] = i; // Shuru mein har node apna khud ka parent hai

        // STEP 1: Connect all adjacent 1s to form the initial islands
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0) continue; // Agar cell 0 (paani) hai, toh skip karo

                // 4 directions move karne ke liye: Left, Up, Right, Down
                int dr[] = {0, -1, 0, 1};
                int dc[] = {-1, 0, 1, 0};

                for(int k = 0; k < 4; k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];

                    // Check grid boundaries aur check karo ki neighbor bhi zameen (1) hai kya
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        int Nodenumber = i * m + j;          // Current cell ka 1D index
                        int adjNodenumber = nrow * m + ncol; // Neighbor cell ka 1D index
                        unionBysize(Nodenumber, adjNodenumber, parent, size); // Dono components ko connect kar do
                    }
                }
            }
        }

        // STEP 2: Try flipping each 0 to 1 and calculate the maximum possible island size
        int maxi = 0; 
        for(int i = 0; i < m; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) continue; // Hum sirf 0 ko 1 mein convert karke check kar rahe hain

                int dr[] = {0, -1, 0, 1};
                int dc[] = {-1, 0, 1, 0};
                
                // Set use kar rahe hain taaki same island 2 baar count na ho jaye
                // (Jaise agar top aur left neighbors same hi island ka part hue)
                set<int> components; 
                
                for(int k = 0; k < 4; k++){
                    int nrow = i + dr[k];
                    int ncol = j + dc[k];
    
                    if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < m && grid[nrow][ncol] == 1){
                        int cellnumber = nrow * m + ncol;
                        // Neighbor wale island ka Ultimate Parent nikal kar set mein daal do
                        components.insert(findParent(cellnumber, parent)); 
                    }
                }

                int totalsize = 1; // 1 isliye kyunki current 0 cell ko humne flip karke 1 bana diya hai
                for(auto it : components){
                    totalsize += size[it]; // Har unique connected island ka size apne 1 mein add kar do
                }
                maxi = max(maxi, totalsize); // Max size ko update karte raho
            }
        }
        
        // Agar grid mein ek bhi 0 nahi tha (yaani pura grid already 1 se bhara hua hai), 
        // toh maxi update nahi hoga (0 reh jayega). Uss case mein total cells (n) return kardo.
        return maxi == 0 ? n : maxi;

    }
};
