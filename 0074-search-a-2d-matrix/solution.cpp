class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int start = 0;
        int end = row*col - 1 ;


        while(start<=end){
            int midindex = (start + end)/2 ;
            int midelement = matrix[midindex/col][midindex%col] ;

            if(midelement == target){
                return 1 ;
            }
            if(midelement < target){
                start = midindex +1 ;
            }
            else{
                end = midindex - 1;
            }
        }
        return 0 ;
    }
};
