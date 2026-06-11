class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // //TC O(N3 X logM)  N3 for three loops and logM for insertion in set which uses balanced binary search tree ans SC O(M) M unique triplets 
        // sort(nums.begin(), nums.end());
        // int n = nums.size();
        // //vector<vector<int>>ans ;
        // // 2D Vector ki jagah Set ka use kyonki phir voh duplicate entry nhi lega 
        // set<vector<int>> st;
        // for(int i =0 ; i<n-2 ; i++){
        //     for(int j = i+1 ; j<n-1 ; j++){
        //         for(int k = j+1 ; k<n ;k++ ){
        //             if(nums[i]+nums[j]+ nums[k] ==0){
        //                 st.insert({nums[i] , nums[j] , nums[k]}) ;
        //             }
        //         }
        //     }
        // }
        // // Set ko 2D vector mein convert karna because output 2d vector hona chahiye 
        // vector<vector<int>> ans(st.begin(), st.end());
        // return ans;

        //method 2 using set and two pointer like nums[i]+nums[j]+nums[k]=0 hai toh main nums[k] = - (nums[i]+ nums[j]) le skte hai jisse hume third loop lene ki jrurat nhi pdegi 
        //TC O(N^2 X log N) n2 for loops and logM and LOGN for insert and find in set toh ek hi baar log wali lenge 
        // Space Complexity (SC): O(N) + O(M)  O(N) for hashset because worst case mai N elements store krega and O(M) for unique triplets in st 
        // int n = nums.size();
        // set<vector<int>>st ;
        // for(int i =0 ; i<n ; i++){
        //     set<int>hashset ;//yeh set i and j ke beech ke element store krega agr uss j element and i ka sum ka negative avavilable nhi hai 
        //     for(int j = i+1 ; j<n ; j++){
        //         int third = - (nums[i]+nums[j]) ;//third element jo hoga voh phle 2 element ke sum ka negative hona chahiye tbhi teeno ka sum 0 aayga 
        //         if(hashset.find(third) != hashset.end()){//eg nums[i] = 1 and nums[j] = 2 and third = - (1+2) = -3 agr hash set mai -3 hua toh yaani triplet mil gyi ek and usse temp mai store krke sort krnege taaki duplicate entry na le kyoni -1,0,1 and 1,0,-1 same hi hai ek baar lenge isliye isse bchne ke liye sort kr rhe hai taaki dono -1,0,1 bn jaaye and set duplicate naa le 
        //             vector<int>temp = {nums[i] , nums[j] , third} ;
        //             sort(temp.begin() , temp.end()) ;
        //             st.insert(temp) ;
        //         }

        //         hashset.insert(nums[j]) ; // agr third nhi mila yaani abhi triplet nhi mili toh hum nums[j] ko hashset mai insert krenge taaki yeh ki aur triplet ke kaam aa skte 
        //     }
        // }

        // vector<vector<int>>ans(st.begin() , st.end()) ;//set ko vapis 2d vetor mai store krenge 
        // return ans ;


        //method 3 optimal and sirf yhi all test cases pass kraygi 
        vector<vector<int>>ans ;
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;

        for(int i = 0 ; i<n ; i++){
            if( i> 0 && nums[i] == nums[i-1]){//agr jaise shuru mai -2 , -2 , -2 , -1 , -1 hai and jaise hi humne i =0 j= 1 and k = n-1 maan kr ag next ke liye aage bdenge toh i++ hoga yaani i=1 pr aajayga and joki -2 hi hog isliye duplicate naa ayye isliye continue likha hai taaki aage bd ke seedha i -1 pr aa jaaye and j = i+1 yaani j bhi next -1 pr hoga 
                continue ;
            }

            int j = i+1 ;
            int k = n-1 ;
            while(j<k){//jab j , k ko cross kr jaaye yaani triplet mil gyi ab i increent hoga yaani ith index ko fix krke jitni triplet mil skti thi mil gyi i seedha non duplicate element pr point krenge yaani -1 pr  due to the above continue wali if contidion 
                int sum = nums[i]+nums[j]+nums[k] ;

                if(sum <0){//agr sum negative hai yaani aur bda krna pdegasum taaki 0 ho isliye j++ krenge kyonki hum nums ko sort kr chuke hai and hume bdi value right mai milgegi
                    j++ ;
                }

                else if(sum >0){
                    k-- ;//same upr ki trh bs sum 0 se bda hai toh choti value chahiye isliye k -- krenge 
                }

                else{//agr sum 0 aa jaaye toh usse temp mai store krke ans mai push krenge and j++ and k-- 
                    vector<int>temp = {nums[i] , nums[j] , nums[k]} ;
                    ans.push_back(temp) ;
                    j++ ;
                    k-- ;
                    while(j<k && nums[j] == nums[j-1]){//jab tk j same milega aage bdenge and j<k hona chahiye yaani j k ko cross naa kre  tbtk j++
                        j++ ;
                    }

                    while(j<k && nums[k] == nums[k+1]){//jab tk k same milega aage bdenge and j<k hona chahiye yaani  k  , j ko cross naa kre  tbtk k-- 
                        k-- ;
                    }
                }
            }
        }
        return ans;


    }
};
