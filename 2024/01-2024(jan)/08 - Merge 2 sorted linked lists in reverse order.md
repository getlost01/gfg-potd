## 08. Merge 2 sorted linked lists in reverse order
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/merge-2-sorted-linked-list-in-reverse-order/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

- Defined a `reverseList` to reverse a linked list recursively.
- Created a`mergeResult` to merge two sorted linked lists in reverse order.
  - Create a new node `curr` and a `head` node to keep track of the merged list.
  - Traverse both lists, comparing elements and merging them in descending order.
  - Update `curr` as you traverse.
  - After one list is exhausted, append the remaining elements of the other list to `curr`.
  - Return the reversed merged list.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N + M)` where N and M are the lengths of the two linked lists.
- **Auxiliary Space Complexity**: O(1)

### Code (C++)

```cpp
class Solution {
public:
    struct Node *reverseList(Node *curr) {
        if (!curr || !(curr->next))
            return curr;
        auto res = reverseList(curr->next);
        curr->next->next = curr;
        curr->next = NULL;
        return res;
    }

    struct Node *mergeResult(Node *node1, Node *node2) {
        if (!node1)
            return reverseList(node2);
        if (!node2)
            return reverseList(node1);

        Node *curr = new Node;
        Node *head = curr;

        while (node1 && node2) {
            if (node1->data < node2->data) {
                curr->next = node1;
                node1 = node1->next;
            } else {
                curr->next = node2;
                node2 = node2->next;
            }
            curr = curr->next;
        }

        while (node1) {
            curr->next = node1;
            node1 = node1->next;
            curr = curr->next;
        }

        while (node2) {
            curr->next = node2;
            node2 = node2->next;
            curr = curr->next;
        }

        head = head->next;
        return reverseList(head);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.