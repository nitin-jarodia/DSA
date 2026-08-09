class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* temp1 = l1;
        ListNode* temp2 = l2;

        ListNode dummy(0);
        ListNode* tail = &dummy;

        int carry = 0;

        while (temp1 || temp2 || carry) {

            int sum = carry;

            if (temp1) {
                sum += temp1->val;
                temp1 = temp1->next;
            }

            if (temp2) {
                sum += temp2->val;
                temp2 = temp2->next;
            }

            carry = sum / 10;

            tail->next = new ListNode(sum % 10);
            tail = tail->next;
        }

        return dummy.next;
    }
};