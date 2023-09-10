class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL){
            return NULL;
        }

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = head;
        while( fast->next != NULL && fast->next->next != NULL ){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                while(slow != temp){
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }   
        }
        return NULL;
    }
};