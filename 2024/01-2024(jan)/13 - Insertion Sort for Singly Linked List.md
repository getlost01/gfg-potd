## 13. Insertion Sort for Singly Linked List
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/insertion-sort-for-singly-linked-list/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
- Traverse the linked list and store each node's data in a vector.
- Use the sort function to sort the vector containing the linked list data.
- Traverse the linked list again and update each node's data with the sorted values from the vector.
- Return the modified linked list.

### Time and Auxiliary Space Complexity
- **Time Complexity**: `O(NlogN)`, where N is the number of nodes in the linked list
- **Auxiliary Space Complexity**: `O(N)`, where n is the number of nodes in the linked list.

### Code (C++)
```cpp
class Solution
{
    public:
    Node* insertionSort(struct Node* head_ref)
    {
        vector<int>ans;
        Node* temp=head_ref;
        while (temp!=nullptr)
        {
            ans.push_back(temp->data);
            temp=temp->next;
        }
        sort(ans.begin(), ans.end());
        temp=head_ref;
        int i=0;
        while (temp!=nullptr)
        {
            temp->data=ans[i];
            i++;
            temp=temp->next;
        }
        return head_ref;
    }
    
};
```

### Contribution and Support
For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
