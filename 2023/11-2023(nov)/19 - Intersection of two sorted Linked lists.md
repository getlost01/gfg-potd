## 19. Intersection of two sorted Linked lists
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/intersection-of-two-sorted-linked-lists/1)

### My Approach
I approach this problem by iterating through both linked lists simultaneously. 
- At each step, I compare the current nodes of both lists. 
- If they have equal values, I add a new node with that value to the result list. 
- If the values are not equal, I move the pointer in the list with the smaller value. This ensures that I only add common elements to the result list.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(M + N)`, where `M` and `N` are the lengths of the two linked lists.
- **Auxiliary Space Complexity**: `O(1)`, as we are not using any extra space proportional to the input.

### Code (C++)
```cpp
class Solution {
public:
    Node* findIntersection(Node* head1, Node* head2)
    {
        Node* head = new Node(0);
        Node* tail = head;
        
        while (head1 && head2) {
            if (head1->data == head2->data) {
                tail->next = head1;
                tail = head1;
                head1 = head1->next;
                head2 = head2->next;
            } else if (head1->data < head2->data)
                head1 = head1->next;
            else
                head2 = head2->next;
        }
        head = head->next;
        tail->next = NULL; 
        
        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.