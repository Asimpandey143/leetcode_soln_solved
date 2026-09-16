class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Compute the length of the list and find the tail
        int length = 1;
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            length++;
        }

        // Step 2: Connect the tail to the head to make it a circular list
        tail->next = head;

        // Step 3: Find the new tail after (length - k % length) steps
        k = k % length;
        int stepsToNewTail = length - k;
        ListNode* newTail = tail;
        while (stepsToNewTail--) {
            newTail = newTail->next;
        }

        // Step 4: Break the circle and return the new head
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
    }
};