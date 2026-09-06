class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int n) {
        n = (n-1)%14+1;//repeat na ho isliye and 14 ke multiples bhi avoid ho 
        //n=14 then 14-1 = 13%14+1 = 14 baar loop chlega 
        //and agr n=16 then 16-1=15%14 = 1+1 =2 baar hi chlega 
        for(int i =0 ; i<n ; i++){
            vector<int>next(8 , 0) ;
            for(int i = 1 ; i<7 ; i++){
                if(cells[i-1] == cells[i+1]){
                    next[i] = 1 ;
                }
                else{
                    next[i] = 0 ;
                }
            }
            cells = next ;
        }

        return cells ;
    }
};
