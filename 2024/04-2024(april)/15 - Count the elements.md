## 15. Count the elements

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-the-elements1529/1)

### My Approach

To count the elements in vector `a` based on the occurrences in vector `b`, I follow these steps:
- Create a frequency array `mp` to count the occurrences of elements in vector `b`.
- Traverse through vector `a` and count the number of elements less than or equal to the current element.
- Store the counts in the output vector for corresponding queries.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N + Q), where N is the size of vector `a` and Q is the number of queries.
- **Auxiliary Space Complexity**: O(nax), where nax is the maximum element present in vector `a`.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> countElements(vector<int> &a, vector<int> &b, int n, vector<int> &query, int q) {
        int nax = *max_element(a.begin(), a.end());
        vector<int> mp(nax + 1, 0);
        for (auto i : b)
            if (i <= nax)
                ++mp[i];

        for (int i = 1; i <= nax; ++i)
            mp[i] += mp[i - 1];

        vector<int> out;
        for (auto i : query)
            out.push_back(mp[a[i]]);

        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.