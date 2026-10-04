class Solution {
public:
    typedef long long LL ;
    // DFS function: 'node' se shuru karke jitne bombs detonate ho sakte hain, unhe count/visit karna
    void dfs(int node , unordered_set<int>&vis , unordered_map<int , vector<int>>&adj   ){
        vis.insert(node) ;

        for(int &nbr : adj[node]){
            if(vis.find(nbr) == vis.end()){
                dfs(nbr , vis , adj) ;
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int , vector<int>>adj ;
        int n = bombs.size() ;
        // Step 1: Directed Graph hi banana pdega  
        // Edge i -> j ka matlab hai ki Bomb 'i' fattne par Bomb 'j' ko bhi detonate karega jruri nhi ki j ke ftne se i bhi ftte isliye directed bnega graph 
        for(int i=0 ; i<n ; i++){//detonate the ith bomb
            for(int j = 0 ; j<n ; j++){
                if(i==j){
                    continue ;
                }

                LL x1 = bombs[i][0] ;
                LL y1 = bombs[i][1] ;
                LL r1 = bombs[i][2] ;

                LL x2 = bombs[j][0] ;
                LL y2 = bombs[j][1] ;
                LL r2 = bombs[j][2] ;
                // Distance ka square nikal rahe hain taaki sqrt() se aane wale precision issues na ho
                LL d = ((x2-x1)*(x2-x1) + (y2-y1)*(y2-y1)) ;

                // Agar bomb 'j', bomb 'i' ke radius ke andar hai, toh edge bana do
                if(r1*r1 >=d){
                    adj[i].push_back(j) ;
                }
            }
        }

        unordered_set<int>vis ;
        int ans = 0 ;
        // Step 2: Har bomb ko individually pehla bomb maan kar DFS chalao aur maximum count track karo
        for(int i=0 ; i<n ; i++){
            dfs(i , vis , adj) ;
            int cnt = vis.size() ;// Is bomb se start karke total kitne bomb phate

            ans = max(ans , cnt) ;
            vis.clear() ;// Next bomb ke liye visited set clear karna zaroori hai
        }

        return ans ;
    }
};
