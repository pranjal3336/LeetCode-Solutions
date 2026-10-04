class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // int n = gas.size() ;
        // for(int i=0 ; i<n ; i++){
        //     if(gas[i] < cost[i]){
        //         continue ;
        //     }

        //     int j = (i+1)%n ;
        //     int costForMovingFromThisStation = cost[i] ;
        //     int gasEarnAtNextStationj = gas[j] ;
            
        //     int currGas = gas[i] - costForMovingFromThisStation + gasEarnAtNextStationj  ;

        //     while(i!= j){
        //         if(currGas < cost[j]){
        //             break ;
        //         }
        //         int costForMovingFromThisj  = cost[j] ;
        //         j = (j+1)%n ;

        //         int gasEarnAtNextStation = gas[j] ;

        //         currGas = currGas - costForMovingFromThisj + gasEarnAtNextStation ;

        //     }

        //     if(j== i){
        //         return i ;
        //     }
        // }
        // return -1 ;
        int n = gas.size() ;
        int totalkamai = accumulate(begin(gas) , end(gas) , 0) ;
        int totalkharch = accumulate(begin(cost) , end(cost) , 0) ;

        if(totalkamai <totalkharch){
            return -1 ;
        }

        int ans = 0 ;
        int total = 0 ;
        for(int i=0 ; i<n ; i++){
           total = total + gas[i] - cost[i] ;

           if(total < 0){
                total = 0 ;
                ans = i+1 ;
           }
        }
        return ans;
    }
};
