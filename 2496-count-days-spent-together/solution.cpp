class Solution {
public:
    int dayofyear(string &date ,vector<int>&temp ){
        int m = stoi(date.substr(0,2)) ;//"MM" tk days nikal rhe hai 
        int d = stoi(date.substr(3)) ;

        return temp[m-1] + d ;
    }
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int>daysinMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} ;

        vector<int>temp(13,0) ;//yeh daystillcurrmonth bta rha hai 

        temp[1] = daysinMonth[0] ;

        for(int i = 2 ; i<=12 ; i++){
            temp[i] = temp[i-1] + daysinMonth[i-1] ;
        }

        int arriveAliceday = dayofyear(arriveAlice , temp) ;
        int leaveAliceday = dayofyear(leaveAlice , temp) ;
        int arriveBobday = dayofyear(arriveBob , temp) ;
        int leaveBobday = dayofyear(leaveBob , temp) ;

        int overlap = min(leaveAliceday , leaveBobday) -max(arriveAliceday , arriveBobday) + 1 ;

        return overlap<0?0:overlap ;




        
    }
};
