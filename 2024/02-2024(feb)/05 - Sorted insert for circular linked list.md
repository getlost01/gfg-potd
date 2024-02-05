## 05. Sorted insert for circular linked list
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/sorted-insert-for-circular-linked-list/1)

### My Approach
- Create a new node with the given data.
-  Check if the linked list is empty. If it is, make the new node the only node in the list.
- If the data in the new node is less than or equal to the data in the head node, insert the new node at the beginning.
- Otherwise, traverse the linked list to find the correct position for the new node.
- Insert the new node in the appropriate position.

### Time and Auxiliary Space Complexity
- **Time Complexity**: O(n) - where n is the number of nodes in the circular linked list.
- **Auxiliary Space Complexity**: O(1) - constant space is used.

### Code (C++)
```cpp
class Solution {
public:
    Node* sortedInsert(Node* head, int data) {
        Node* newNode = new Node(data);

        if (!head) {
            newNode->next = newNode;
            return newNode;
        }

        Node* curr = head;
        Node* next = curr->next;

        if (data <= curr->data) {
            newNode->next = head;
            while (curr->next != head)
                curr = curr->next;

            curr->next = newNode;
            return newNode;
        }

        while (next != head && data > next->data) {
            curr = next;
            next = next->next;
        }

        curr->next = newNode;
        newNode->next = next;

        return head;
    }
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.