#ifndef ALGORITHM_LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
#define ALGORITHM_LEETCODE_21_MERGE_TWO_SORTED_LISTS_H

#include "utility.h"

class Solution21_MergeTwoSortedLists {
public:
    static ListNode* MergeTwoLists_Recursive(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        if (list1->val < list2->val) {
            list1->next = MergeTwoLists_Recursive(list1->next, list2);
            return list1;
        } else {
            list2->next = MergeTwoLists_Recursive(list1, list2->next);
            return list2;
        }
    }

    static ListNode* MergeTwoLists_InPlaceMerge(ListNode* list1, ListNode* list2) {
        if (list1 == nullptr) return list2;
        if (list2 == nullptr) return list1;
        ListNode head;
        ListNode* current = &head;
        while (list1 != nullptr && list2 != nullptr) {
            if (list1->val > list2->val) {
                current->next = list2;
                list2 = list2->next;
            } else {
                current->next = list1;
                list1 = list1->next;
            }
            current = current->next;
        }
        if (list1 != nullptr) current->next = list1;
        if (list2 != nullptr) current->next = list2;
        return head.next;
    }

    static void Test() {
        auto* list1 = new ListNode(1, new ListNode(2, new ListNode(4)));
        auto* list2 = new ListNode(1, new ListNode(3, new ListNode(4)));
        LOG(Solution21_MergeTwoSortedLists::MergeTwoLists_Recursive(list1, list2)->ToString());
    }
};

#endif //ALGORITHM_LEETCODE_21_MERGE_TWO_SORTED_LISTS_H
