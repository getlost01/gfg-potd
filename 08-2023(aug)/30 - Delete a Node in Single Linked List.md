## 30. Delete a Node in Single Linked List

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/delete-a-node-in-single-linked-list/1)

### My Approach

I will find the node that needs to be deleted and adjust the pointers accordingly to remove it from the linked list.

- If the node to be deleted is the first node (`x == 1`):
  - Update the `head` to point to the next node.
- Otherwise, for any other node:
  - Traverse the list until reaching the node just before the one to be deleted.
  - Adjust pointers to skip the node to be deleted.
- Free the memory of the node to be deleted.

### Explanation with Example

Let's say we have a linked list: `1 -> 2 -> 3 -> 4 -> 5` and we want to delete the node at index `3`.

- **Step 1:** Check if `x` is `1`. Since it's not, proceed to the else block.
- **Step 2:** Traverse the linked list till `x - 1`. In this case, traverse till `x = 2`.
- **Step 3:** Adjust pointers to skip the node containing `3`.

The linked list after deletion: `1 -> 2 -> 4 -> 5`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)` We need to traverse the linked list to find the node to be deleted, which takes linear time.
  
- **Auxiliary Space Complexity**: `O(1)` We are using a constant amount of extra space for temporary variables.

### Code (C++)

```cpp
class Solution {
public:
    Node* deleteNode(Node *head, int x) {
        Node *toDelete;
        
        if (x == 1) {
            toDelete = head;
            head = head->next;
        } else {
            Node* itr = head;
            --x;
            while (--x) 
                itr = itr->next;
           
            toDelete = itr->next;
            itr->next = itr->next->next;
        }
       
        free(toDelete);
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.