class Solution {
public:
    int findParent(int node , vector<int>&parent){
        if(node == parent[node]){
            return node ;
        }

        return parent[node] = findParent(parent[node] , parent) ;
    }

    void unionSet(int u , int v , vector<int>&parent , vector<int>&rank ){
        u = findParent(u , parent) ;
        v = findParent(v , parent) ;

        if(rank[u]<rank[v]){
            parent[u] = v ;
        }
        else if(rank[v] < rank[u]){
            parent[v] = u ;
        }

        else{
            parent[u] = v;
            rank[v]++ ;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n);
        vector<int> rank(n, 0);
        
        // DSU Initialization
        for(int i = 0; i < n; i++) parent[i] = i;

        // STEP 1: Mail -> Node (Account Index) Mapping
        unordered_map<string, int> mp; 
        for(int i = 0; i < n; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                if(mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i; // Naya mail mila toh uske account index (i) par map karo
                } else {
                    // Mail already mapped hai, matlab 'i' aur purana mapped node same person ke hain
                    unionSet(i, mp[accounts[i][j]], parent, rank);
                }
            }
        }

        // STEP 2: Grouping Mails using Array of Vectors
        // CONCEPT: mergeMail array ka har index ek "vector (bag)" hai. 
        // Array of string vectors jisme ultimate parent wale index par saare mails collect honge.
        vector<string> mergeMail[n]; 
        for(auto it : mp) {
            string mail = it.first;
            int node = findParent(it.second, parent); // Ultimate parent nikalo
            mergeMail[node].push_back(mail); // Us parent ke specific bag me mail push kar do
        }

        // STEP 3: Formatting and Sorting output
        vector<vector<string>> ans;
        for(int i = 0; i < n; i++) {
            if(mergeMail[i].size() == 0) continue; // Khali bags ko ignore karo
            
            // i-th locker/bag ke andar wale strings ko sort karo
            sort(mergeMail[i].begin(), mergeMail[i].end()); 
            
            vector<string> temp;
            temp.push_back(accounts[i][0]); // 0th index par jo naam tha, wo push karo
            
            for(auto it : mergeMail[i]) {
                temp.push_back(it); // Sorted mails add karo
            }
            ans.push_back(temp);
        }

        return ans;
    }
};
