class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lengthA = 0;
        ListNode* tempA = headA;
        while(tempA != NULL){
            lengthA++;
            tempA = tempA->next;
        }

        int lengthB = 0;
        ListNode* tempB = headB;
        while(tempB != NULL){
            lengthB++;
            tempB = tempB->next;
        }

        int diff = abs(lengthA - lengthB);

        tempA = headA;
        tempB = headB;

        if(lengthA>lengthB){
            while(diff > 0){
                diff--;
                tempA = tempA->next;
            }
        }
        else{
            while(diff > 0){
                diff--;
                tempB = tempB->next;
            }
        }

        while(tempA != tempB){
            tempA = tempA->next;
            tempB = tempB->next;
            if(tempA == NULL || tempB == NULL){
                return NULL;
            }
        }
        return tempA;
    }
};