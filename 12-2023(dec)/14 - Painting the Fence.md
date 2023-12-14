## 14. Painting the Fence
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/painting-the-fence3727/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
I'm solving this problem using a dynamic programming approach. I maintain three variables: `same`, `diff`, and `total`. At each step, I update these variables according to the given recurrence relation. The loop iterates from 2 to n, updating the variables in each iteration.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n)` - The loop runs for n iterations.

- **Auxiliary Space Complexity**: `O(1)` - The algorithm uses a constant amount of space for variables regardless of the input size.

### Code (C++)
```cpp
class Solution {
public:
    long long countWays(int n, int k){
        long mod = 1e9 + 7;
        long same = 0;
        long diff = k;
        long total = same + diff;

        for(int i = 2; i <= n; ++i) {
            same = diff * 1;
            diff = (total * (k - 1)) % mod;
            total = same + diff;
        }
        return total % mod;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.