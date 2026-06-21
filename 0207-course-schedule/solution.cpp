class Solution {
public:
    
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        unordered_map<int , list<int>> adj ;
        
        for(int i = 0 ; i<pre.size() ; i++){
            int u = pre[i][0] ;
            int v = pre[i][1] ;
            
            adj[u].push_back(v) ;
        }
        
        vector<int>indegree(numCourses) ;
        //indegree nikal rhe hai 
        for(auto i:adj){
            for(auto j : i.second){//j yaani neighbour ki indegree increase hogi 
                indegree[j]++ ;
            }
        }
        
        queue<int>q ;//jiski indegree 0 usse q mai push kr rhe 
        for(int i = 0 ; i<numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i) ;
            }
        }
        
        //ab dfs lgaenge 
        
        vector<int> ans ;
        
        while(!q.empty()){
            int frontnode = q.front() ;
            q.pop() ;
            
            ans.push_back(frontnode) ;
            
            //neighbour traversing
            for(auto j:adj[frontnode]){
                indegree[j]-- ;
                if(indegree[j]==0){
                    q.push(j) ;
                }
            }
        }
        if(ans.size() == numCourses){
            return true ;
        }
        return false ;
    }
};
