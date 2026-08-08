class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length() ;
        int m = word2.length() ;
        // Step 1: Right-to-left suffix matching array banate hain
        // rightSideMatchLength[i] ye batata hai ki index i ke baad (right side mein) 
        // word2 ke kitne characters suffix ke roop mein match ho chuke hain.
        vector<int>rightSideMatchLength(n) ;
        int i = n-1 ; 
        int j = m-1 ;
        int rightMatch = 0 ;
        while(i>=0 ){
            if(j>=0 && word1[i] == word2[j]){
                rightMatch++ ;// Agar character match hua, toh match count badhao
                j-- ; // word2 ke pointer ko peeche le jao
            }
            rightSideMatchLength[i] = rightMatch ;
            i-- ;
        }
        // Step 2: Left-to-right greedy traversal start karte hain
        // Lexicographically sabse chhota (smallest) index sequence banane ke liye
        i = 0 ;
        j = 0 ;
        vector<int>ans ;
        bool changePower = true ;// Wildcard power available hai ya nahi (at most 1 character change) yaani abhi koi bhi ek character change nhi kra hai
        while(i<n && j < m){
            // Case A: Agar characters already match ho rahe hain
            // Toh bina wildcard waste kiye direct greedy choice lo (kyunki exact match hamesha best hai).
            if(word1[i] == word2[j]){
                ans.push_back(i) ;
                j++ ;
            }
            // Case B: Agar match nahi hua, par hum wildcard use kar sakte hain (`changePower == true`)
            // Aur check karte hain ki aage ka bacha hua word2 ka part (`m - j - 1`) 
            // word1 ke right side ke matched suffix (`rightSideMatchLength[i+1]`) se fulfill ho sakta hai ya nahi.
            else if(changePower == true &&  i+1 <n && rightSideMatchLength[i+1] >= m-j-1){
                ans.push_back(i) ;// Wildcard use karke current index ko include kar liya
                j++ ;
                changePower = false ;
            }
            i++ ;
            
        }
        // Step 3: Check karo ki kya poora word2 successfully construct ho gaya hai
        if(j == m){
            return ans ;
        }

        return {} ;// Agar poora match nahi hua, toh empty vector return karo

    }
};
