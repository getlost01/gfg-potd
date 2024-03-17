## 17. Count Pairs whose sum is equal to X
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-pairs-whose-sum-is-equal-to-x/1)

### My Approach
To solve this problem, I utilize a hash set to store the elements of the first linked list. Then, I iterate through the second linked list, checking if the difference between the target sum and the current element exists in the hash set. If it does, I increment the count of pairs. Finally, I return the count of pairs found.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n + m)`, where n is the number of elements in the first linked list and m is the number of elements in the second linked list.
- **Auxiliary Space Complexity**: `O(n)`, where n is the number of elements in the first linked list.

### Code (C++)

```cpp
class Solution {
public:
    int countPairs(struct Node* head1, struct Node* head2, int x) {
        unordered_set<int> st;
        while (head1) {
            st.insert(head1->data);
            head1 = head1->next;
        }
        int cnt = 0;
        while (head2) {
            if (st.find(x - head2->data) != st.end())
                ++cnt;
            head2 = head2->next;
        }
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.