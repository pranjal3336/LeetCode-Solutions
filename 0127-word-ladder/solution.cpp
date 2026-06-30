class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // BFS use karenge kyunki 'shortest transformation sequence' pucha hai
        queue<pair<string , int>>q ;
        q.push({beginWord , 1}) ; // Store: {current_word, steps_taken}
        
        // Dictionary lookup ko O(1) banane aur visited words track karne ke liye set
        unordered_set<string>st(wordList.begin() , wordList.end()) ;
        st.erase(beginWord) ; // Infinite loop se bachne ke liye start word ko hata do

        while(!q.empty()){
            string top = q.front().first ;
            int steps = q.front().second ;
            q.pop() ;

            // Target mil gaya, BFS guarantee karta hai ki yahi shortest path hai
            if(top == endWord){
                return steps ;
            }

            // Word ke har character ko modify karke sab possibilities check karenge
            for(int i=0 ; i<top.length() ; i++){
                char original = top[i] ; // Restore karne ke liye original character save kiya
                
                // 'a' se 'z' tak har letter lagakar dekho
                for(char ch ='a' ; ch<='z' ; ch++){
                    top[i] = ch ; 
                    
                    // Agar transformed word hamari dictionary (set) mein hai
                    if(st.find(top) != st.end()){
                        st.erase(top) ; // Set se hatao (acted as marked visited)
                        q.push({top , steps+1}) ; // Naya valid word queue mein agle level (steps+1) par
                    }
                }
                // Backtrack: Agle index ko change karne se pehle current word ko wapas normal karo
                top[i] = original ; 
            }
        }
        
        // Agar endWord tak koi rasta nahi mila
        return 0 ;
    }
};
