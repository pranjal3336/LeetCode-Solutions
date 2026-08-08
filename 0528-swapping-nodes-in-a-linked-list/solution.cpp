/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        // int n = 0 ;//total length nikal rhe hai 
        // ListNode* temp = head ;
        // while(temp  != NULL){
        //     temp = temp -> next ;
        //     n++ ;
        // }

        // int k_1 = k ;//kth node from begining 
        // ListNode* temp1 = head ;
        // while(k_1 >1){
        //     temp1 = temp1 -> next ;
        //     k_1-- ;
        // }
        // int k_2 = n -k + 1 ; // kth node from last mtlb  n-k+1 node from starting 
        // ListNode* temp2 = head ;
        // while(k_2 >1){
        //     temp2 = temp2 -> next ;
        //     k_2-- ;
        // }
        // //temp1 and temp2 kth node from start and last show kr rhe hai unko hi swap krna hai 
        // swap(temp1 -> val , temp2 -> val) ;

        // return head ;

        //method 2 
        ListNode* p1 = NULL ;//store kth node from start 
        ListNode* p2 = NULL ;//store kth node from last 

        ListNode* temp = head ;
        while(temp != NULL){
            //jab p1 aachuka h apni jgh then hum p2 ko active krenge yaani head se aage bdaygnge and temp ko aage bdayge and jb temp bahr nikl jayga jb p2 last node from k yaani n -k + 1 node from begin pr hoga 
            if(p2 != NULL){
                p2 = p2 -> next ;
            }

            k-- ;
            // Jab k decrement hote-hote 0 ho jaye, matlab hum first se 'kth' node par hain yaani p1 apni position pr pahuch gya and p2 ko active kr denge 
            if(k == 0){
                p1 = temp ;// p1 ko kth node from start mil gaya
                p2 = head ;// p2 ko head par initialize karke end distance ke liye ready kar diya
            }
            temp = temp -> next ;
        }
        // p1 (kth from start) aur p2 (kth from end) ki values ko swap kar do
        swap(p1 -> val , p2-> val) ;
        return head ;




    }
};
