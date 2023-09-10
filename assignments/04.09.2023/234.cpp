class Solution {
public:
bool isPalindrome(ListNode* head) {
    ListNode* fast = head;
    ListNode* slow = head;
    ListNode* pre = NULL;
      
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;

        
        ListNode* nextOfTemp = slow->next;
        slow->next = pre;
        pre = slow;
        slow = nextOfTemp;
    }
    
    if (fast != NULL) {
        slow = slow->next;
    }
    while (pre != NULL && slow != NULL) {
        if (pre->val != slow->val) {
            return false;
        }
        pre = pre->next;
        slow = slow->next;
    }
    return true;
}
};