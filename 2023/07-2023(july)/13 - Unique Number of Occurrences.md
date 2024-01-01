## 13. Unique Number of Occurrences

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/unique-frequencies-of-not/1)


### My Approach

This is a straightforward question where we calculate the frequency of each element using a `map`. After obtaining the frequency of each element, we use a `set` to determine if there are any duplicate frequencies among the elements in the array `arr`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(n), as we traverse an array of size `n`.
- **Auxiliary Space Complexity**: O(n), due to the unordered_map `freq` and the set `uniqueSet`.

### Code (C++)
```cpp
class Solution {
public:
    bool isFrequencyUnique(int n, int arr[]) {
        unordered_map<int, int> freq;
        unordered_set<int> uniqueSet;

        for (int i = 0; i < n; ++i)
            ++freq[arr[i]];

        for (auto i : freq)
            uniqueSet.insert(i.second);

        return freq.size() == uniqueSet.size();
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.