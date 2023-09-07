## 07. Minimum Multiplications to reach End

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1)

### My Approach

By initial intuition, we recognized that this problem could be solved using dynamic programming (DP). However, considering the constraints, we realized that the DP approach would potentially involve a maximum of `1e4 x 1e5` iterations and require a 2D matrix to store intermediate results. Given these constraints, there is a risk of encountering Time Limit Exceeded (TLE) issues. Therefore, we needed to explore a more efficient solution.

Generally, the Breadth-First Search (BFS) approach is typically preferred when searching for the minimum number of steps or levels type questions. Therefore, I used BFS to find the desired answer.

- Create a vector `dp` of size `MOD` to store the minimum number of multiplications needed to reach each state.
- Initialize `dp[start]` to 0, as we start from `start`.
- Create a queue to perform BFS and Push `start` into the queue.
- While the queue is not empty, do the following:
  - Store and Pop the front element `current` from the queue.
  - For each element `arr[i]` in the input array, calculate the next state as `(1LL * current * arr[i]) % MOD`.
  - If `dp[next]` is -1 (meaning it's not visited yet), update `dp[next]` to `dp[current] + 1` and push `next` into the queue.
  - If `next` is equal to `end`, return `dp[next]` as we have reached the desired state.
- If the loop completes and we haven't reached `end`, return -1, indicating it's not possible to reach `end` from `start`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: As we iterate through elements that haven't been visited yet, the maximum number of iterations is limited to `MOD`. Therefore, the time complexity of this algorithm is `O(MOD)`.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(MOD)` as we use a `dp` array of size MOD to store intermediate results.

### Code (C++)
```cpp
class Solution {
public:
    int MOD = 100000;
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        if (start == end)
            return 0;

        int n = arr.size();
        vector<int> dp(MOD, -1);

        dp[start] = 0;

        queue<int> q;
        q.push(start);

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            for (int i = 0; i < n; i++) {
                long long next = (1LL * current * arr[i]) % MOD;

                if (dp[next] == -1) {
                    dp[next] = dp[current] + 1;
                    q.push(next);

                    if (next == end) {
                        return dp[next];
                    }
                }
            }
        }

        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.