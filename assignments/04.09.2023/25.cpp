class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {        
        ListNode* temp = head;

        for(int i = 0; i<k; i++){
            if(temp == NULL) return head;
            temp = temp->next;
        }

        if(head == NULL){
            return NULL;
        }
        
        ListNode* pre = NULL;
        ListNode* curr = head;
        ListNode* ptr = NULL;

        int x = 0;
        while (curr != NULL && x<k){
            ptr = curr->next;
            curr->next = pre;
            pre = curr;
            curr = ptr;
            x++;
        }        
        head->next = reverseKGroup(ptr, k);
        return pre ;
        
        
    }
};