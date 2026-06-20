class Solution {
public:
    bool bfs(int i ,vector<vector<int>>& graph , vector<int>&color ){
        //agr graph ke nodes ko sirf 2 color se covered kr diya and adjecent node ka same color nhi hona chahiye tb hi bipartitie graph hoga 
        //hume ek trh se adjacency list hi given hai 

        //using bfs
        int n = graph.size() ; //no of nodes 
        queue<int>q ;
        color[i] = 0 ;
        q.push(i) ;
        while(!q.empty()){
            int top  = q.front() ;
            q.pop() ;

            //traversing neighbours ;
            for(auto nbr : graph[top]){
                if(color[nbr] == -1){//yaani node visit nhi kra and uska color array mai default value hai yaani -1 and ab iska color iske parent node yaani top jiska yeh nbr hai usse alg hona chaahiye isliye !color[top] likha hai jisse agr top ka color 0 hoga toh iska 1 ho jayga vrna 0 ho jayga 
                    color[nbr] = !color[top] ;
                    q.push(nbr) ;
                }
                else if(color[nbr] == color[top]){//agr nbr colord hai and iska parent yaani top ka bhi same color hai toh yeh bipartite nhi hai kyunki adjacent node ka same color ho gya joki nhi hona chihiye tha  isliye return false krenge 
                    return false ;
                }
            }
        }
        return true ;//agrupr se return false nhi hua yaani queue empty and graph bipartite hai return true krenge 

    }
    bool isBipartite(vector<vector<int>>& graph) {
        //agr graph ke nodes ko sirf 2 color se covered kr diya and adjecent node ka same color nhi hona chahiye tb hi bipartitie graph hoga 
        //hume ek trh se adjacency list hi given hai 

        //using bfs
        int n = graph.size() ; //no of nodes 
        vector<int>color(n , -1) ;
        bool ans = true ;
        //for loop lgaya hai kyonki graph discoonected bhi ho skta hai 
        for(int i=0 ; i<n ; i++){
            if(color[i] == -1){
                ans = ans && bfs(i , graph , color ) ;
            }
            
        }
        return ans ;
    }
};
