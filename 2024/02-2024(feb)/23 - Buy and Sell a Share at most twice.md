## 23. Buy and Sell a Share at most twice
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/buy-and-sell-a-share-at-most-twice/1)

### My Approach
To solve this problem, I utilize a dynamic programming approach to track the maximum profit achievable by making transactions at each day. Specifically:
- I iterate through the prices array once to compute the maximum profit that can be obtained by making one transaction up to that day and store it in the 'left' array.
- Then, I iterate through the prices array in reverse to compute the maximum profit that can be obtained by making two transactions. During this iteration, I combine the profit obtained from the first transaction (stored in 'left' array) with the profit obtained by selling on the current day.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(n)`, where n is the number of elements in the `price` vector.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n)`, where n is the number of elements in the 'price' vector.

### Code (C++)
```cpp
class Solution {
public:
    int maxProfit(vector<int>& price) {
        int n = price.size();
        vector<int> left(n, 0);
        int nin = price[0];
        int out = 0;
        for (int i = 1; i < n; ++i) {
            nin = min(nin, price[i]);
            left[i] = max(left[i - 1], price[i] - nin);
            out = max(out, left[i]);
        }
        
        int nax = price[n - 1];
        for (int i = n - 2; i > 0; --i) {
            nax = max(nax, price[i]);
            out = max(out, left[i - 1] + nax - price[i]);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.