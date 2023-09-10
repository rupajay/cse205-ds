class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* hare;
        ListNode* tortoise;
        hare = head;
        tortoise = head;

        while(hare != NULL && hare->next != NULL){
            tortoise = tortoise->next;
            hare = hare->next->next;

        }
        return tortoise;
    }
};