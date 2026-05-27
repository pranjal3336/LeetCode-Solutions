class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int a = 0 ;
        int b = 0 ;
        bool flag = false ;
      
        for(int i = 0 ; i<bills.size() ; i++){
            if(bills[i]== 5){
                a++ ;
                flag = true ;
            }
            if(bills[i] == 10){
                if(a >=1){
                    b++ ;
                    a-- ;
                    flag = true ;
                }
                else{
                    flag = false ;
                    break ;
                }
            }

            if(bills[i] == 20){
                if(a>= 1 && b>=1){
                    flag = true ;
                    b-- ;
                    a-- ;
                }

                else if(a >=3 && b<1){
                    flag = true ;
                    a = a -3 ;
                }

                else{
                    flag = false ;
                    break ;
                }
            }
        }

        return flag ;
    }
};
