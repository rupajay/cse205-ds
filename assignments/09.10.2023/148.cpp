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

ListNode* Mid(ListNode* head){
    ListNode* slow = head;
    ListNode* fast = head;

    while(fast->next && fast->next->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

ListNode* mergeSortedLists(ListNode* p1, ListNode* p2){
    if(p1 == NULL || p2 == NULL){
        if(p1 == NULL){
            return p2;
        }
        else{
            return p1;
        }
    }

    ListNode* ans = new ListNode(0);
    ListNode* curr = ans;

    while(p1 && p2){
        if(p1->val < p2->val){
            curr->next = p1;
            p1 = p1->next;
        }
        else{
            curr->next = p2;
            p2 = p2->next;
        }
        curr = curr->next;
    }

    if(p1 || p2){
        if(p1){
            curr->next = p1;
            p1 = p1->next;
        }
        else{
            curr->next = p2;
            p2 = p2->next;
        }
    }

    return ans->next;
}

    ListNode* sortList(ListNode* head) {

        if(!head || !head->next){
            return head;
        }

        ListNode* mid = Mid(head);
        ListNode* newHead = mid->next;
        mid->next = NULL;

        ListNode* leftHalf = sortList(head);
        ListNode* rightHalf = sortList(newHead);

        return mergeSortedLists(leftHalf, rightHalf);
    
    }
    
};