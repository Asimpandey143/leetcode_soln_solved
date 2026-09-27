class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) {
            return head;
        }

        // Dummy node to handle edge cases like reversing from the head (left = 1)
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Move prev to the node immediately before the 'left' position
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // 'start' is the first node of the sublist to be reversed
        // 'then' is the node that will be moved to the front of the reversed sublist
        ListNode* start = prev->next;
        ListNode* then = start->next;

        // Reverse the sublist in a single pass
        for (int i = 0; i < right - left; ++i) {
            start->next = then->next;
            then->next = prev->next;
            prev->next = then;
            then = start->next;
        }

        return dummy.next;
    }
};