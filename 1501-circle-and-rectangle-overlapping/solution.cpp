class Solution {
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        //sabse phle rectangle ka nearest point dekhenge jo circle ke sbse paas hai 
        //uss point ko (xi , yi) bolenge ab xi and yi ki value nikalenge 

        //for xi 
        int xi ;
       
        if(x1 > xCenter){
            xi = x1 ;
        }
        else if(x2<xCenter){
            xi = x2 ;
        }
        else {
            xi = xCenter ;
        }

        //for yi
        int yi ;

        if(y1 > yCenter){
            yi = y1 ;
        }
        else if(y2<yCenter){
            yi = y2 ;
        }
        else {
            yi = yCenter ;
        }


        //ab xi and yi mil gye 
        //ab hum iska circle ke center se distance nikalenge 

        int d = (xi-xCenter)*(xi-xCenter) + (yi-yCenter)*(yi-yCenter) ;//hume d = sqrt(x2-x1)2 + (y2-y1)2 nhi likha hum baad mai jab circle ki radius se comapre krenge tb r ko square kr denge 

        if(d <= radius*radius){
            return true ;
        }

        return false;

    }
};
