## 24. Buy Maximum Stocks if i stocks can be bought on i-th day

The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/buy-maximum-stocks-if-i-stocks-can-be-bought-on-i-th-day/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach

To solve this problem, I used a greedy approach. 
- I first created a vector of pairs, where each pair represents the stock price and its corresponding day. 
- Then, I sorted this vector based on stock prices in ascending order.
- Next, I iterated through the sorted vector, calculating the maximum number of stocks that can be bought on each day without exceeding the available budget. 
- I kept track of the total number of stocks bought, and the remaining budget after each purchase.

### Time and Auxiliary Space Complexity

- **Time Complexity:** The time complexity is dominated by the sorting operation, making it `O(n log n)`, where 'n' is the number of stocks.
- **Auxiliary Space Complexity:** `O(n)`, where 'n' is the number of stocks, for storing the vector of pairs.

### Code (C++)

```cpp
class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]) {
        vector<pair<int, int>> v;
        for (int i = 0; i < n; ++i)
            v.push_back({price[i], i + 1});

        sort(v.begin(), v.end());

        int out = 0;

        for (auto i : v) {
            int maxBuy = min(k / i.first, i.second);
            out += maxBuy;
            k -= i.first * maxBuy;
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.