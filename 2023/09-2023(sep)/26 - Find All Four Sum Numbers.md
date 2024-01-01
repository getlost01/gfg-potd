## 26. Find All Four Sum Numbers

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-all-four-sum-numbers1732/1)

### My Approach

To find all four sum numbers in the given array, by intuition these are the task we need to do.

1. Sort the input array.
2. Iterate through the array with two pointers (`q1` and `q2`) to fix two numbers.
3. Use two more pointers (`q3` and `q4`) to find the remaining two numbers such that their sum equals the target (`k`).
4. Handle duplicates to avoid duplicate solutions.

To do so, I follow these steps.

1. Sort the input array `arr` in ascending order.
2. Initialize an empty vector `out` to store the result.
3. Use two nested loops to select the first two elements of the quadruplet:
    - The outer loop iterates for `q1` from `0 to n - 1`, where `n` is the size of `arr`.
        - If `q1 > 0` and `arr[q1]` is equal to `arr[q1 - 1]`, skip this iteration to avoid duplicate results.
    - The inner loop iterates for `q2` from `q1+1 to n - 1`.
        - If `q2 > q1 + 1` and `arr[q2]` is equal to `arr[q2 - 1]`, skip this iteration to avoid duplicate results.
        - Calculate the remaining two numbers `q3` and `q4` using two pointers:
            - Initialize `q3 = q2 + 1` and `q4 = n - 1`.
            - While `q3 < q4`, calculate the sum of the current quadruplet `(arr[q1] + arr[q2] + arr[q3] + arr[q4])`.
                - If the sum is equal to `k`, add the quadruplet to the `out` vector and increment `q3` and decrement `q4`.
                    - Also, skip duplicates in `q3` and `q4` to avoid duplicate results.
                - If the sum is less than `k`, increment `q3`.
                - If the sum is greater than `k`, decrement `q4`.
4. Return the `out` vector containing all unique quadruplets that sum up to `k`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n^3)` - This is because we have three nested loops in the worst case, where `n` is the length of the input array.
- **Auxiliary Space Complexity**: `O(1)` - We use only a constant amount of space for variables and the output vector.

### Code (C++)

```cpp
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, int k) {
        int n = arr.size();
        vector<vector<int>> out;

        sort(arr.begin(), arr.end());

        for (int q1 = 0; q1 < n; ++q1) {
            if (q1 > 0 && arr[q1] == arr[q1 - 1])
                continue;

            for (int q2 = q1 + 1; q2 < n; ++q2) {
                if (q2 > q1 + 1 && arr[q2] == arr[q2 - 1])
                    continue;

                int q3 = q2 + 1, q4 = n - 1;

                while (q3 < q4) {
                    int sum = arr[q1] + arr[q2] + arr[q3] + arr[q4];

                    if (sum == k) {
                        out.push_back({ arr[q1], arr[q2], arr[q3], arr[q4] });
                        q3++;
                        q4--;

                        while (q3 < q4 && arr[q3] == arr[q3 - 1])
                            q3++;
                        while (q3 < q4 && arr[q4] == arr[q4 + 1])
                            q4--;
                    } else if (sum < k)
                        q3++;
                    else
                        q4--;
                }
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.