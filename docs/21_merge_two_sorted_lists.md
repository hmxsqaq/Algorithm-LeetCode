# 21. Merge Two Sorted Lists

You are given the heads of two sorted linked lists `list1` and `list2`.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

## Recursive Merge

The recursive solution is simple. We compare the heads of the two lists and merge the rest of the lists recursively.

```c++
ListNode* MergeTwoLists_Recursive(ListNode* list1, ListNode* list2) {
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
```

- Time complexity: $O(N+M)$
- Space complexity: $O(N+M)$

## In-place Merge

Just like the merge step in merge sort, we can merge two sorted linked lists in-place.

Worth noting that we use a dummy node to keep the head of linked lists, which can simplify the code.

```c++
ListNode* MergeTwoLists_InPlaceMerge(ListNode* list1, ListNode* list2) {
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
```

- Time complexity: $O(N+M)$
- Space complexity: $O(1)$