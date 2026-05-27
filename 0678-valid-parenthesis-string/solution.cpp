class Solution {
public:
    bool checkValidString(string s) {
        stack<int> open ;
        stack<int> star ;
        int i = 0 ;
        
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                open.push(i) ;//hum index store kr rhe h open bracket ke 
                
            }

            else if(s[i] == '*'){
                star.push(i) ;//hum index store kr rhe h star ke 
               
            }

            else{// agr ) aaya toh 
                //phle try krenge ki ( yeh available h ya nhi 
                if(!open.empty()){
                    open.pop() ;
                }

                //phir agr ( nhi hai toh * check krenge agr yeh hua toh phir * ko pop krenge 
                else if(!star.empty()){
                    star.pop() ;
                }
                else{//nothing available then false return krenge 
                    return false ;
                }
            }
        }

        while(!open.empty() && !star.empty()){
            // '*' should come after '(' because *( valid nhi hoga pr (* yeh valid hoga kyonki * ko hum as a closing bracket use krlenge 
            if(open.top() < star.top()){
                star.pop() ;
                open.pop() ;
            }
            else{
                return false ;
            }
        }

        return open.empty() ;//agr while loop faail hua and agr open stack empty hua toh true hoga and agr star empty hua but open nhi hai toh false aayga because * ko toh empty string le skte hai but (  ka kuch nhi kr skte 

        
    }
};
