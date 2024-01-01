## 03. Pythagorean Triplet
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/pythagorean-triplet3018/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

A simpler and direct approach, I have used a unordered set to store the squares of all elements in the array, which are unique and help eliminate duplicate checks. 
Next, I'll iterate through all pairs of elements (a, b) in the set and verify if their sum (a + b) exists in the set. If it does, we've identified a Pythagorean triplet.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N^2)`, where `N` is the number of elements in the array.
- **Auxiliary Space Complexity**: `O(N)`, where `N` is the number of elements in the array.

### Code (C++)
```cpp
class Solution {
public:
    bool checkTriplet(int arr[], int n) {
        unordered_set<int> s;

        for (int i = 0; i < n; ++i)
            s.insert(arr[i] * arr[i]);

        for (auto a : s) {
            for (auto b : s) {
                if (s.find(a + b) != s.end())
                    return true;
            }
        }
        
        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.