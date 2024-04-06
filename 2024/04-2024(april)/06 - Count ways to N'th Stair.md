## 06. Count ways to N'th Stair
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-ways-to-nth-stairorder-does-not-matter1322/1)

### My Approach
To count the ways to the N'th stair, we observe that for each step, we can either take 1 step or 2 steps. This forms a Fibonacci sequence, where the N'th element represents the number of ways to reach the N'th stair. So, our approach is to return (N/2) + 1.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(1)
- **Auxiliary Space Complexity**: O(1)

### Code (C++)
```cpp
class Solution {
public:
    long long countWays(int n) {
        return n / 2 + 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.