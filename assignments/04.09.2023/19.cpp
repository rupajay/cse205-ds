class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
       
        for(int i = 1; i<=n; i++){
            fast = fast->next;
        }

        if(fast == NULL){
            return head->next;
        }

        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next;
        }

        if(slow!=NULL && slow->next!=NULL){
            slow->next = slow->next->next;
        }
        return head;
    }
};