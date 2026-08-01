class Solution {
public:
    string winningPlayer(int x, int y) {
        //hum 4 and 1 se isliye divide kr rhe hai kyonki 115 bs 1 75 ke and 4 10 ke coin se bn skta hai 
        int b = y/4 ;//yha hum no of y coin in grp of 4 nial rhe hai jisse pta lge kitni baar chl skte hai and no of x coins ke lie x/1 krna hota jo ki x hi aata isliye direct x , b ka jo minumn hoga voh no of turns btayga 

        int r = min(x , b) ;//no of turns

        if(r%2 ==0){//if no of turns even then game ka winner BOB hai kyonki even mtlb dusre bnde ki baari pr khtm hua hai game vrna alice hogi agr odd no of turns aata 
            return "Bob" ;
        }
        return "Alice" ;
    }
};
