## 09. Smallest Positive missing number

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/smallest-positive-missing-number-1587115621/1)

### My Approach

To find the missing number in an array of integers, I have used an `unordered map` to store the presence of each element. Then, iterate through the array and mark each element as present in the map. After that, start from `1` and keep incrementing `nin` until I find the first number that is not present in the map. Finally, return that missing number.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)`, where `n` is the size of the input array. This is because we iterate through the array once to mark the presence of elements in the unordered map.
- **Auxiliary Space Complexity**: `O(n)` since we use an unordered map to store the presence of elements.

### Code (C++)

```cpp
class Solution {
public:
    int missingNumber(int arr[], int n) {
        unordered_map<int, bool> mp;
        
        // Mark presence of elements in the map
        for(int i = 0; i < n; ++i) {
            mp[arr[i]] = true;
        }
        
        int nin = 1;
        
        // Find the first missing number
        while(true) {
            if(mp.find(nin) == mp.end())
                return nin;
            ++nin;
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.