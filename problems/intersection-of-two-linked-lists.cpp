/*************************************************************
* problem id : 160
* problem title : Intersection of Two Linked Lists
* problem link : https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*************************************************************/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *curA=headA, *curB=headB;

        if(curA==nullptr || curB==nullptr)
            return nullptr;
        while(curA!=nullptr && curB!=nullptr && curA!=curB) {
            curA = curA->next;
            curB = curB->next;
            if(curA==curB)
                return curA;
            if(curA==nullptr)
                curA = headB;
            if(curB==nullptr)
                curB = headA;
        }
        return curA;
    }
};
