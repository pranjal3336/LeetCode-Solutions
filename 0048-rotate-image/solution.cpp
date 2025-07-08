class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
       //transpose lena h
       int row= matrix.size();
       int col = matrix[0].size();


       for(int i=0;i<row;i++){
        for(int j= i+1 ; j< col ; j++){
            swap(matrix[i][j], matrix[j][i]);
        }
       } 

       for(int m=0;m<row;m++){
        reverse(matrix[m].begin() , matrix[m].end());
       }
    }
};
