## 11. Adding Ones

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/adding-ones3628/1)

### My Approach

To solve the problem, I have used the following approach:

- Initialize a vector `out` of size n+1 with all elements initially set to 0. This vector will be used to store the counts of each number.
- Traverse the `updates` array and increment the count in the `out` vector for each number encountered.
- Initialize the first element of the `arr` array as the count of 1 in the `out` vector.
- Traverse the `arr` array starting from the second element. Set each element as the sum of the previous element in the `arr` array and the count of the corresponding number in the `out` vector.
- Finally, the `arr` array stores the cumulative counts of each number from 1 to n.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(k + n)`, where `k` is the size of the `updates` array and `n` is the size of the `arr` array. We traverse the `updates` array once and the `arr` array once, performing constant-time operations in each iteration.
- **Auxiliary Space Complexity**: `O(n)` since we use an additional vector `out` of size `n+1` to store the counts of each number.

### Code (C++)

```cpp
class Solution{
    public:
    void update(int arr[], int n, int updates[], int k){
        vector<int> out(n+1, 0);
        for(int i = 0; i < k; ++i){
            ++out[updates[i]];
        }
        arr[0] = out[1];
        for(int i = 2; i <= n; ++i){
            arr[i-1] = arr[i-2] + out[i];
        }
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.