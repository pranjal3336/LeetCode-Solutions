class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
       //kahns algo lgaya hai jism e bfs use hota hai 
       //yeh same toposort se cycle detect krni thi directed graph mai agr cycle hui toh saare course nhi le skte mtlb valid toposort nhi aayga yaani empty array return krenge vrna aa gya toh valid toposort return krenge 
       //aur haan iss questio mai ai , bi mtlb bi hoga tb ai le paayenge yaani adjacency list mai u to v nhi v to u bnaenge edge kyonki baad wala jruri hai yaani baad wale se phle wale ki trf edge bnega 

       unordered_map<int , list<int>> adj ;
        vector<int>indegree(numCourses , 0) ;
        for(int i = 0 ; i<pre.size() ; i++){
            int u = pre[i][0] ;
            int v = pre[i][1] ;
            
            adj[v].push_back(u) ;
            indegree[u]++ ;
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

       if(ans.size() == numCourses){//valid topo order mil gya yaani no cycle 
        return ans ;
       } 

       return {} ;
    }
};
