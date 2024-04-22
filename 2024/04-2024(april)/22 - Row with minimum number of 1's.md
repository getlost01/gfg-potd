## 22. Row with minimum number of 1's
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1)

### My Approach
To find the row with the minimum number of 1's, I traverse through each row, calculating the sum of each row. If the sum of the current row is less than the sum of the previous minimum row, update the minimum row index.

### Time and Auxiliary Space Complexity

- **Time Complexity** : O(n * m)
- **Auxiliary Space Complexity** : O(1)

### Code (C++)

```cpp
class Solution {
public:
    int minRow(int n, int m, vector<vector<int>> a) {
        int out = 0;
        for(int i = 0; i < n; ++i){
            for(int j = 1; j < m; ++j)
                a[i][j] += a[i][j-1];
            if(a[out].back() > a[i].back())
                out = i;
        }
        return out + 1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.