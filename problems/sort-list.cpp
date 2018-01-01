/****************************************************************
* problem id : 148
* problem title : Sort List
* problem link : https://leetcode.com/problems/sort-list/description/
*****************************************************************/

class Solution {
public:
    int count_size(ListNode *head) {
        int sum = 0;
        ListNode *cur = head;

        while(cur!=nullptr) {
            sum ++;
            cur = cur->next;
        }

        return sum;
    }

    ListNode* sortList(ListNode* head) {
        int block_size = 1, n = count_size(head), iter = 0, i = 0, a = 0, b = 0;
        ListNode virtual_head(0);
        ListNode *last = NULL, *it = NULL, *A = NULL, *B = NULL, *tmp = NULL;
        virtual_head.next = head;
        while (block_size < n){
            iter = 0;
            last = &virtual_head;
            it = virtual_head.next;
            while (iter <  n){
                a = min(n - iter, block_size);
                b = min(n - iter - a, block_size);

                A = it;
                if (b != 0){
                    for (i = 0; i < a - 1; ++i) it = it->next;
                    B = it->next;
                    it->next = NULL;
                    it = B;

                    for (i = 0; i < b - 1; ++i) it = it->next;
                    tmp = it->next;
                    it->next = NULL;
                    it = tmp;
                }

                while (A || B){
                    if (B == NULL || (A != NULL && A->val <= B->val)){
                        last->next = A;
                        last = last->next;
                        A = A->next;
                    } else {
                        last->next = B;
                        last = last->next;
                        B = B->next;
                    }
                }
                last->next = NULL;
                iter += a + b;
            }
            block_size <<= 1;
        }
        return virtual_head.next;

    }
};
