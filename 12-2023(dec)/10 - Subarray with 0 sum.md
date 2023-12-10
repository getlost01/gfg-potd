## 10. Subarray with 0 sum
 The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/subarray-with-0-sum-1587115621/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
To check if there is a subarray with a sum of 0, I maintain a running sum while traversing the array. I use an unordered set to store the cumulative sum at each step. If, at any point, I find that the sum already exists in the set, it means there is a subarray with a sum of 0. This is because the difference between the current sum and the sum stored in the set would be 0.

### Explain with Example
Consider the array [4, 2, -3, 1, 6]. The running sum would be [4, 6, 3, 4, 10]. At the third step, the sum becomes 4, and we check if 4 is already in the set. Since it is, we know there is a subarray with a sum of 0 (from index 1 to 3: `2 - 3 + 1`).

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(n)`, where n is the size of the array.
- **Auxiliary Space Complexity** : `O(n)`, where n is the size of the array.

### Code (C++)
```cpp
class Solution {
public:
    bool subArrayExists(int arr[], int n) {
        int sum = 0;
        unordered_set<int> s;
        s.insert(0);
        
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            if (s.find(sum) != s.end())
                return true;
            s.insert(sum);
        }
        
        return false;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.