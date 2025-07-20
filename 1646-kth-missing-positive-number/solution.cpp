class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int misindex =0 ;
        int curr =1;

        int i=0;

        while(true){
            if(i<arr.size() && curr == arr[i]){
                i++;
            }
            else{
                misindex++;
            }

            if(misindex == k){
                return curr ;
               
            }

             curr++ ;
        }




    }
};
