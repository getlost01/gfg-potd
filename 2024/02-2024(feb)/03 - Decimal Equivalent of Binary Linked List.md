## 03. Decimal Equivalent of Binary Linked List
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/decimal-equivalent-of-binary-linked-list/1)

### My Approach
- I am iterating through the linked list, treating it as a binary representation of a number.
- At each step, I shift the current result left by one bit (multiply by 2) and add the current node's data.
- I also take care to update the result modulo 1e9 + 7 to avoid overflow.
  
### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where N is the number of nodes in the linked list.
- **Auxiliary Space Complexity** : O(1)

### Code (C++)
```cpp
class Solution {
public:
    long long unsigned int decimalValue(Node *head)
    {
        long long unsigned int out = 0, mod = 1e9 + 7;
        Node* temp = head;

        while (temp) {
            out = (out << 1) % mod;
            out = (out + temp->data) % mod;
            temp = temp->next;
        }

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.