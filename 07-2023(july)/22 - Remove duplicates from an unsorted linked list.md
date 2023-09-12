## 22. Remove duplicates from an unsorted linked list

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/remove-duplicates-from-an-unsorted-linked-list/1)


### My Approach

To remove duplicates from a linked list, we can use a hash map to keep track of the elements we have encountered so far. 
- We traverse the linked list, and for each node.
	- Check if the data of the current node is already present in the hash map. If it is, skip the node by adjusting the pointers accordingly. To achieve this, I use `skipItr` for iterating, effectively skipping all duplicate elements. Once all duplicate elements are skipped, I link the `skipItr` with the current `itr`.
	- If it is not present in the hash map, mark the data as seen and proceed to the next node.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` represents the number of nodes in the linked list. Since we traverse the linked list once.

- **Auxiliary Space Complexity**: `O(N)`. In the worst-case scenario, where all elements in the linked list are unique, they will be stored in the unordered hash map.


### Code (C++)

```cpp
class Solution {
public:
    Node *removeDuplicates(Node *head) {
        unordered_map<int, bool> isDup;
        Node* itr = head;
        Node* skipItr;

        while (itr) {
            isDup[itr->data] = true;
            skipItr = itr->next;

            while (skipItr && isDup.find(skipItr->data) != isDup.end())
                skipItr = skipItr->next;

            itr->next = skipItr;
            itr = skipItr;
        }

        return head;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.