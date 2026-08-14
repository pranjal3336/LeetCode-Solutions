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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        
        // Step 1: Find the total length of the linked list
        int n = 0;
        ListNode* curr = head;
        while (curr != NULL) {
            n++;
            curr = curr->next;
        }
        
        curr = head;
        ListNode* prev = NULL;
        
        int nodesIneachgrp = n / k;
        int extra = n % k; // Extra nodes to distribute among the first few parts
        
        // Step 2: Split the list into k parts
        for (int i = 0; i < k; i++) {
            ans[i] = curr;
            
            // Traverse the nodes for the current part
            for (int cnt = 1; cnt <= nodesIneachgrp + (extra > 0 ? 1 : 0); cnt++) {
                prev = curr;
                curr = curr->next;
            }
            
            // Break the link to isolate the current part
            if (prev != NULL) {
                prev->next = NULL;
            }
            extra--;
        }
        
        return ans;


    }
};
