class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
       //kahns algo lgaya hai jism e bfs use hota hai 
       //yeh same toposort se cycle detect krni thi directed graph mai agr cycle hui toh saare course nhi le skte mtlb valid toposort nhi aayga yaani ans ka size nodes yaani numCourses ke equal nhi aaya toh false krenge vrna agr aa gya yaani valide toposort toh true 
       unordered_map<int , list<int>> adj ;
        
        for(int i = 0 ; i<pre.size() ; i++){
            int u = pre[i][0] ;
            int v = pre[i][1] ;
            
            adj[v].push_back(u) ;
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
        return ans ;
       } 

       return {} ;
    }
};
