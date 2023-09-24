## 24. Find duplicates in an array

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-duplicates-in-an-array/1)

### My Approach
To find duplicates in the given array, 
- I use an array `cnt` to keep track of the count of each element in the input array `arr`. 
- Then, I iterate through the `cnt` array and push the indices of elements with a count greater than 1 to the `out` vector. 
- Finally, if there are duplicates, I return the `out` vector; otherwise, I return {-1} to indicate no duplicates.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the size of the input array. This is because we iterate through the input array once to count the occurrences of each element and then iterate through the `cnt` array once to find duplicates.
- **Auxiliary Space Complexity**: `O(n)`, as we use an additional array `cnt` to store the counts of elements.

### Code (C++)
```cpp
class Solution {
public:
    vector<int> duplicates(int arr[], int n) {
        int cnt[n] = {0};
        for(int i = 0; i < n; ++i)
            ++cnt[arr[i]];

        vector<int> out;
        for(int i = 0; i < n; ++i)
            if(cnt[i] > 1)
                out.push_back(i);

        if(out.size())
            return out;

        return {-1};
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.