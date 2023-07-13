## GFG Problem Of The Day

### 🎉 Announcement
I have created a Git Book that contains all previous editorials for my GFG-POTD solutions. You can visit **[here](https://gl01.gitbook.io/gfg-editorials/)** to access it and refer to my previous solutions. In the future, I intend to establish a contribution flow, where others can contribute their solutions to this Git Book. I would appreciate hearing your thoughts and views on this in the [discussion section](https://github.com/getlost01/gfg-potd/discussions).

----
### Today - 13 July 2023
### Que - Unique Number of Occurrences

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

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.


![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
