## 05. Count Possible Ways to Construct Buildings

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/count-possible-ways-to-construct-buildings5007/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

The problem involves determining the total number of ways to construct buildings on plots along a road. The constraint is that no two buildings can be adjacent, and this restriction also applies to buildings on opposite sides of the road. The goal is to find a count of valid arrangements for a given number of plots.

To approach this problem:

- Initialize three variables, `curr`, `prev`, and `next`, which represent the count of valid arrangements for the current, previous, and next plots, respectively.

-  Iterate through the plots from 1 to N, updating the `next` count as the sum of `curr` and `prev`, taking care of the modulo operation (`mod`). This step ensures that we calculate the number of valid arrangements for the current plot based on the counts of valid arrangements for the previous two plots.

- Update `prev` and `curr` for the next iteration.

- The final result is calculated as `(curr * curr) % mod`. This represents the total number of ways to construct buildings on both sides of the road without violating the adjacency rule.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this solution is `O(N)` since there is a single loop that iterates N times.

- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(1)` since only a constant amount of extra space is used.

### Code (C++)

```cpp
class Solution {
public:
    int mod = 1e9 + 7;

    int TotalWays(int N) {
        long long curr, prev, next;
        curr = prev = 1;
        for (int i = 1; i <= N; ++i) {
            next = (curr + prev) % mod;
            prev = curr;
            curr = next;
        }

        return (curr * curr) % mod;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.