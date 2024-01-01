## 28. Remove duplicate element from sorted Linked List

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/remove-duplicate-element-from-sorted-linked-list/1)

### My Approach

I start traversing the linked list while comparing each node with its next node. 
- If they have the same data, I update the current node's `next` pointer to skip the duplicate node. This way, I remove duplicates in a single pass through the linked list.

### Explanation with example

Let's say we have a sorted linked list: `1 -> 1 -> 2 -> 3 -> 3 -> 3 -> 4`

- **Step 1**: Initialize `curr` as the head of the list (`1`).
- **Step 2**: Inside the outer loop, initialize `next` as `curr->next`.
- **Step 3**: Inside the inner loop, compare `next->data` with `curr->data`.
- **Step 4**: If they are equal, update `next` to `next->next` until we find a different value (`2` in this case).
- **Step 5**: Update `curr->next` to `next`, effectively skipping the duplicates.
- **Step 6**: Move `curr` to `next` (now pointing to `2`).
- **Step 7**: Repeat the process until we reach the end of the list.

After this process, the list becomes: `1 -> 2 -> 3 -> 4`

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where n is the number of nodes in the linked list. We traverse the list once.
- **Auxiliary Space Complexity**: `O(1)`, as we use a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    Node *removeDuplicates(Node *head)
    {
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            while (next && next->data == curr->data)
                next = next->next;
            curr->next = next;
            curr = curr->next;
        }
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.