class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // unordered_set<int>s ;//for storing all unique xor pairs 
        // int n= nums.size() ;
        // for(int i=0 ; i<n ;i++){
        //     for(int j = i ; j<n ; j++){
        //         s.insert(nums[i]^nums[j]) ;
        //     }
        // }

        // unordered_set<int>t ;//ab jo s ke andr pairs hai unka nums ke har ek element se xor kr rhe hai taaki 3 elements ka xor mil jaaye and unque ho kyonki set unique store krta hai 
        // for(int a : s){
        //     for(int&b : nums){
        //         t.insert(a ^ b) ;
        //     }
        // }

        // return t.size() ;//jo t ka size hoga vhi answer hoga jitne unique 3 elemenst ke triplets honge 

        //method 2 using array insted of set kyonki hume pta hai maximum next 2 ki power different xor aa skte hai 

        int n = nums.size() ;
        int maxi = *max_element(begin(nums) , end(nums)) ;//nums mai se max element nikal rha hu and jo yeh hoga 2 ki power utna krenge jo just isse bda ho utna hi max value jaa skti hai kisi bhi xor ki 
        
        // Step 1: Max possible XOR value ke liye next power of 2 nikaalo
        int T = 1 ;//2 ki power 0 
        while(T <= maxi){
            T = T*2 ; //2 ki power nikal rhe hai 
        }

        vector<bool>temp1(T , false) ;// temp1 -> saare possible 2-element XORs track karega
        vector<bool>temp2(T , false) ;// temp2 -> saare possible 3-element XORs (triplets) track karega

        // Step 2: Har 2-element pair ka XOR mark karo yaani array mai uss index ko true kr denge jo as a xor mil skta hai kisi 2 lements ka xor krke 
        for(int i=0 ; i<n ;i++){
            for(int j = i ; j<n ; j++){
                temp1[nums[i]^nums[j]] = true  ;
            }
        }

        // Step 3: Pehle ke XOR ko 3rd element ke sath XOR karke 3-element XOR banao
        for(int i=0 ; i<T ; i++){
            if(temp1[i] == true){
                for(int &j : nums){
                    temp2[i ^ j] = true ;
                }
            }
        }

        int cnt = 0 ;// Step 4: Saare unique 3-element XORs count kar lo jo bhi true honge temp2 mai 
        for(int i=0 ; i<T ; i++){
            if(temp2[i] == true){
                cnt++ ;
            }
        }
        return cnt ;
    }
};
