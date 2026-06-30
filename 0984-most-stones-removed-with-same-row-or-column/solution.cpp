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


    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size() ;
        
        // DSU ke liye parent aur size arrays initialize kar rahe hain
        vector<int>parent(n) ;
        vector<int>size(n ,1) ;
        
        // Shuru mein maan lete hain ki har stone independent hai, 
        // isliye har node khud ka hi parent hai.
        for(int i=0 ; i<n ; i++) parent[i] = i ;

        // O(N^2) loop - Hum har stone ko check kar rahe hain ki kya wo kisi doosre stone se jud sakta hai
        for(int i=0 ; i<n ; i++){
            // j = i+1 se start karke hum self-comparison (i==j) aur pehle check ho chuke pairs ko avoid kar rahe hain
            for(int j =i+1 ; j<n ; j++){
                // Condition: Agar do stones same row (0th index) YA same column (1st index) mein hain
                if(stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1] ) {
                    // Toh unko ek hi set (component) mein daal do.
                    // Hum i ke parent aur j ko union kar rahe hain.
                    unionBysize(findParent(i, parent) , j , parent , size) ; //kyonki kya pta i ka bhi koi parent ho isliye seedha j ko root se connect krenge 
                }
            }
        }
        
        int components = 0 ;
        
        // Ab humein ginna hai ki total kitne independent groups (components) bane hain
        for(int i=0 ; i<n ; i++){
            // DSU ki property: Kisi bhi component ka sirf ek hi root/representative hota hai 
            // jiska parent wo khud hota hai.
            if(parent[i] == i){
                components++ ; // Naya component mil gaya
            }
        }

        // Logic: Ek connected component mein se hum sirf ek stone ko bacha kar 
        // baaki saare stones remove kar sakte hain. 
        // Toh total removed stones = Total stones - (1 stone per component jise hum hata nahi sakte)
        return n - components ;
    }
};
