## 02. Construct list using given q XOR queries
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/construct-list-using-given-q-xor-queries/1)

### My Approach
- Initialize an empty vector `ans` and add `0` to it. Also, initialize a variable `xorr` to `0`.
- Iterate through each query in `queries`.
  - If the first element of the query `x[0]` is `1`, update `xorr` by XORing it with `x[1]`.
  - If the first element of the query `x[0]` is `0`, append `xorr XOR x[1]` to `ans`.
- After processing all queries, XOR each element in `ans` with the final value of `xorr`.
- Sort the `ans` vector.
- Return the sorted `ans` vector.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(n log n)`, where n is the number of elements in `ans` due to the sorting step. Each query operation (XOR and append) takes constant time.
- **Auxiliary Space Complexity**: `O(n)`, where n is the number of elements in the `ans` vector.

### Code (C++)

```cpp
class Solution {
public:
    vector<int> constructList(int q, vector<vector<int>> &queries) {
        vector<int>ans;
        ans.push_back(0);
        int xorr=0;
        for(auto x:queries){
            if(x[0]) xorr^=x[1];
            else ans.push_back(xorr^x[1]);
        }
        for(int &x:ans) x^=xorr;
        sort(begin(ans), end(ans));
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.