## 30. Shortest path from 1 to n
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/shortest-path-from-1-to-n0156/1)

### My Approach
This is a basic greedy problem. To solve it, I begin with a value `n` and try to reach `1`. I employ a while loop as long as `n` is greater than `1`:
- At each step, I either divide `n` by `3` if it's divisible by `3`, or subtract `1`.
- I repeat this procedure until `n` becomes `1`, keeping track of the number of steps.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(log n))` - The time complexity is logarithmic because in each step, the value of `n` is either divided by 3 or subtracted by 1.
- **Auxiliary Space Complexity**: `O(1)` - The algorithm uses a constant amount of space.

### Code (C++)
```cpp
class Solution {   
public:
    int minimumStep(int n) {
        int cnt = 0;
        while (n > 1) {
            if (n % 3 == 0)
                n /= 3;
            else
                n -= 1;
            ++cnt;
        }
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.