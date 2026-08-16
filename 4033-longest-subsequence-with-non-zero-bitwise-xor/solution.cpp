class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xor_all = 0;
        int n = nums.size() ;
        bool allzeroes = true ;
        for(int i=0 ; i<n; i++){
            if(nums[i] !=0){
                allzeroes = false ;//ek bhi agr element non zero hua toh isko false mark kr denge 
            }
            xor_all = nums[i]^xor_all ;
        }

        
        if(allzeroes == true){//agr saare element 0 hue toh unko xor humesha 0 aayga and non zero naa hone ki vjh se hum 0 return krenge 
            return 0 ;
        }

        if(xor_all != 0){//purra array le lenge 
            return n ;
        }

        return n-1 ;//agr pura array ka zeroaa rha h toh hum ek element hta denge jisse n-1 answer ho jayga 
    }
};
