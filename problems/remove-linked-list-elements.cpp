/********************************************************************
* problem id : 203
* problem title : Remove Linked List Elements
* problem link : https://leetcode.com/problems/remove-linked-list-elements/description/
********************************************************************/

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode **list = &head;

        while (*list != nullptr) {
            if ((*list)->val == val) {
                *list = (*list)->next;
            }
            else
                list = &(*list)->next;
        }

        return head;
    }
};
