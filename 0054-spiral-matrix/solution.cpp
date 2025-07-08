class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int count =0;
        int row = matrix.size();
        int col = matrix[0].size();
        int total = row*col ;
        int startingrow = 0;
        int startingcol = 0;
        int endingrow = row - 1;
        int endingcol = col -1 ;
        vector<int> ans ;

        while(count < total){
            //printing starting row 
            for(int index =startingcol; count <total && index<= endingcol ; index++){
                ans.push_back(matrix[startingrow][index]);
                count++;
            }
            startingrow++;
            //printing ending column 
            for(int index =startingrow; count <total && index<= endingrow ; index++){
                ans.push_back(matrix[index][endingcol]);
                count++;
            }
            endingcol--;
            //printing ending row 
            for(int index =endingcol ; count <total && index>= startingcol ; index--){
                ans.push_back(matrix[endingrow][index]);
                count++;
            }
            endingrow--;
            //printing starting column 
            for(int index =endingrow; count <total && index>= startingrow ; index--){
                ans.push_back(matrix[index][startingcol]);
                count++;
            }
            startingcol++;
        }
        return ans;

    }
};
