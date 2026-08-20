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
    ListNode* rotateRight(ListNode* head, int k) {
        // vector<int>ans ;
        // if(head == NULL){
        //     return head ;
        // }
        // ListNode* temp = head ;
        // while(temp!=NULL){
        //     ans.push_back(temp -> val);
        //     temp = temp -> next ;
        // }

        // int i =0 ;
        // int j = ans.size()-1 ;
        // k = k% ans.size();
        // while(i<=j){
        //     swap(ans[i] , ans[j]) ;
        //     i++ ;
        //     j-- ;
        // }
        // i =0 ;
        // j = k-1 ;

        // while(i<=j){
        //     swap(ans[i] , ans[j]) ;
        //     i++ ;
        //     j--;
        // }
        // i =k ;
        // j = ans.size()-1 ;
        // while(i<=j){
        //     swap(ans[i] , ans[j]) ;
        //     i++ ;
        //     j-- ;
        // }

        // ListNode* first = new ListNode(ans[0]);
        // ListNode* temp1 = first ;
        // int x = 1 ;
        // while(x<ans.size()){
        //     ListNode* curr = new ListNode(ans[x]) ;
        //     temp1 -> next = curr ;
        //     temp1 = curr ;
        //     x++ ;
        // }

        // return first ;

        //method 2 without array 
        if(head == NULL || head ->next == NULL|| k==0){
            return head ;
        }
        int L = 1 ;
        ListNode* tail = head ;//last tk le jaa rhe hai isse 
        while(tail ->next != NULL){
            L++ ;
            tail = tail -> next ;
        }

        k = k%L ;
        if(k == L){//agr k==l hua toh yaani rotation nhi krni hai 
            return head ;
        }
        //phle list ko circular bna rhe hai 
        tail -> next = head ;
        int remain = L - k ;//shuru se kitna aage jakr break krna hai voh remain btayga 

        ListNode* temp = head ;
        for(int i=1 ; i<remain ; i++){
            temp = temp -> next ;
        }
        ListNode* newHead = temp -> next ;//break krna h jis node ko uske next node ko new head bolenge 
        temp -> next = NULL ;//break kr rhe h list ko
        return newHead ;//new head return krr he hai 

       
        

    }
};
