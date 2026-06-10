class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        //har row mai like row no 2 mai 2 hi element honge mai index ki nhi row no ki baat kr rha hu jaise first row mai 1 element hai 

        //3 type ke question pucche jaa skte hai 
        //ques1 N=4(i=3) , C=3(j=2) wala element btao pascal triangle ka toh isme hum NCR wala formulara use krenge N!/ R! (N-R)!  bas jitna row and column number diya hoga uska ek kam use krenge formula mai 3!/1! * 2! = 3 aayga jo ki hai bhi  

        //ques2 usme koi N=3 row print kra lenge same formula use krke saare element nikal denge 

        //ques3 jo yeh given hai saare element print krane ke liye 

        vector<vector<int>>ans(numRows) ;//ans vector ki row toh jitna numRows given hoga utni hi hogi 
        for(int i =0 ; i<numRows ; i++){
            ans[i].resize(i+1) ;//ans vector ke columns for each row , row ke idex se decide honge like i=2 ke liye i+1 elements aayenge yaani column size = 3 lenge ,   column ko each row ke liye resize krna pdega 
            ans[i][0] = ans[i][i] = 1 ;//har row ke starting and ending element 1 hai dekh skte hai 

            for(int j =1 ; j<i ; j++){// yeh loop j=1 se less than i tk chlega because last element toh 1 hai hi 
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j] ; //hum dekh skte hai koi bhi row ka element apni se above wali row ke col -1 and same col ka sum hai 
            }
        }

        return ans ;
    }
};
