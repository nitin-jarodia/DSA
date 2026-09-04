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
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while (curr != NULL) {
            ListNode* next = curr->next;

            curr->next = prev;

            prev = curr;

            curr = next;
        }
        return prev;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* curr = head;

        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        head = reverse(head);

        if (n == 1) {
            head = head->next;
        } else {

            ListNode* curr = head;

            for (int i = 1; i < n - 1; i++) {
                curr = curr->next;
            }
            curr->next = curr->next->next;
        }

        

        head =  reverse(head);

        return head;
    }
};