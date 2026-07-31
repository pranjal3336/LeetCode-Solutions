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
    vector<int>arr ;//array mai LINked list ke saare elemts daal rhe hai 
    Solution(ListNode* head) {
        ListNode* temp = head ;
        while(temp != NULL){
            arr.push_back(temp->val) ;
            temp = temp -> next ;
        }
    }
    
    int getRandom() {
        int n = arr.size() ;
        int random_index = rand()%n ;//yeh jo rand() function hai yeh humesha random number generte krega phir uska mod n se kr rhe hai kyonki array ka index 0 to n-1 hai isliye random index 0 to n-1 mai aa jayga and ussi arr index ki value de denge 

        return arr[random_index] ;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
