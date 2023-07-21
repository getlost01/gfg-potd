## 21. Reverse a Linked List in groups of given size

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/reverse-a-linked-list-in-groups-of-given-size/1)

### My Approach

To reverse the linked list in groups of K, I used a recursive approach.
- I maintained three pointers, `prev`, `curr`, and `temp`, to keep track of the previous, current, and next nodes respectively. 
- I also used a variable `it` to keep track of the remaining elements to reverse in the current group. 
- I iterated through the linked list, reversing the pointers, and reducing the `it` count until either the group is fully reversed or we reach the end of the linked list.
- I recursively called the function for the remaining linked list and linked it with current head.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of nodes in the linked list. 
- **Auxiliary Space Complexity**: `O(N/K)`, where `K` is the size of the group to reverse. The recursion stack uses space for `N/K` function calls.

### Code (C++)

```cpp
class Solution {
public:
    struct node *reverse(struct node *head, int k) {
        if (head == NULL)
            return head;

        struct node *prev = NULL, *curr = head, *temp = head;
        int it = k;

        while (it-- && curr) {
            temp = temp->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        head->next = reverse(curr, k);

        return prev;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.