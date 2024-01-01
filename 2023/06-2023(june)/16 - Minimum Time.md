## 16. Minimum Time

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/95bb244da24edd6214086ff934886ccda6ed9da8/1)

### My Approach

To find the minimum time required to collect fruits from different locations, I have used the following approach:

- First, I create a container called `col` to store the minimum and maximum values for each fruit type.
- Then, I create a vector called `type` to store the different types of fruits we have.
- Using a loop, I iterate through the locations and types. For each fruit type, I update the minimum and maximum values in the `col` container.
- Additionally, I add type 0 to `col` with a value of 0, since we start from 0, and type 1000002 with a value of 0, since we end at 0.
- Next, I iterate through the `col` container and store the different fruit types in the `type` vector.
- I calculate the total number of fruit types we have, `tsz`.
- Using the `dp` array, I implement a tabulation-based dynamic programming approach to optimize the solution. The `dp` array is initialized to store the minimum time for each fruit type and position.
- I iterate through the `type` vector in reverse order and calculate the minimum time required to reach the end from each position.
- Finally, I return the minimum time between the two possible starting positions, `dp[0][0]` and `dp[0][1]`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)`, where `N` is the number of locations. The loop to process the locations and types runs in `O(N)` time. The loop to calculate the minimum time using dynamic programming also takes `O(N)` time.
- **Auxiliary Space Complexity**: `O(N)` since we use additional space to store the `col` container and the `type` vector.

### Code (C++)

```cpp
class Solution {
public:
    long long minTime(int n, vector<int>& locations, vector<int>& types) {
        map<int, vector<int>> col;
        vector<int> type;
        
        for (int i = 0; i < n; ++i) {
            if (col.find(types[i]) == col.end()) {
                col[types[i]] = vector<int>(2, locations[i]);
            } else {
                col[types[i]][0] = min(col[types[i]][0], locations[i]);
                col[types[i]][1] = max(col[types[i]][1], locations[i]);
            }
        }

        col[0] = vector<int>(2, 0);
        col[1000002] = vector<int>(2, 0);

        for (auto i : col)
            type.push_back(i.first);

        int tsz = type.size();
        long long dp[tsz + 1][2], lastval, offset;
        dp[tsz][0] = dp[tsz][1] = 0;

        for (int i = tsz - 1; i >= 0; --i) {
            for (int li = 1; li >= 0; --li) {
                auto loc = col[type[i]];

                lastval = col[type[i - 1]][li];
                offset = abs(loc[0] - loc[1]);

                dp[i][li] = offset + min(dp[i + 1][1] + abs(lastval - loc[0]), dp[i + 1][0] + abs(lastval - loc[1]));
            }
        }

        return min(dp[0][0], dp[0][1]);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.