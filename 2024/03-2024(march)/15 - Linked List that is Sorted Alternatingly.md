## 15. Linked List that is Sorted Alternatingly
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/linked-list-that-is-sorted-alternatingly/1)

### My Approach
To solve this problem,
- I traverse the linked list and split it into two lists, one with nodes at even positions (starting from 1) and the other with nodes at odd positions.
- Reverse the list containing nodes at odd positions.
- Merge the two lists alternatively to get the required arrangement.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(n)`, where n is the number of nodes in the linked list.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` as we are using only a constant amount of extra space.

### Code (C++)
```cpp
class Solution {
public:
    Node* reverse(Node* head) {
        Node* prev = nullptr;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    void sort(Node **head)
    {
        if (!(*head) || !(*head)->next)
            return;

        Node *asc = (*head), *des= (*head)->next;
        Node* revStart = des;
        
        while (des && des->next) {
            asc->next = des->next;
            asc = asc->next;
            des->next = asc->next;
            des = des->next;
        }
        
        Node* temp = reverse(revStart);
        asc->next = temp;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.