class Solution {
public:
    int maxArea(vector<int>& arr) {
        int A = -1 ;
        int l =0 ;
        int r = arr.size() -1 ;

        while(l<r){
            int w = r - l ;
            int newA = min(arr[l] , arr[r])*w ;
            A = max(A , newA) ;

            if(arr[l]<arr[r]){
                l++ ;
            }
            else{
                r-- ;
            }
        }

        return A ;
    }
};
