## GFG Problem Of The Day

### Today - 22 April 2024
### Que - Row with minimum number of 1's
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/row-with-minimum-number-of-1s5430/1)

### Note: 
##### Due to constant travelling, I am unable to provide the solution for next 4-5 days, so if anyone is interested in contributing, please create a PR with the solution and I will merge it as soon as possible. Thank you for your support.

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

I always encourage contributors to participate in the discussion forum for this repository.

If you have a better solution or any queries / discussions related to the `Problem of the Day` solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.

![Total number of repository visitors](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)
![](https://hit.yhype.me/github/profile?user_id=79409258)

