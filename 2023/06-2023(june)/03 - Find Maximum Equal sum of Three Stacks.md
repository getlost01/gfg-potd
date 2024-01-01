## 03. Find Maximum Equal sum of Three Stacks

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/find-maximum-equal-sum-of-three-stacks/1)

### My Approach

To find the maximum equal sum among three given arrays (`S1`, `S2`, and `S3`), I have used the following approach:

1. Initialize an unordered map `mp` to store the cumulative sums of the elements encountered so far and their frequencies.
2. Traverse the first array (`S1`) in reverse order. At each index, calculate the cumulative sum `s` by adding the current element to the previous sum. Increment the frequency of `s` in the map `mp`.
3. Similarly, traverse the second array (`S2`) in reverse order. At each index, calculate the cumulative sum `s` by adding the current element to the previous sum. Check if `s` exists in the map `mp`. If it does, increment its frequency in the map.
4. Repeat the same process for the third array (`S3`).
5. Iterate through the map `mp` and find the maximum sum (`out`) for which the frequency is equal to 3.
6. Finally, return the value of `out`.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N1 + N2 + N3)`, where `N1`, `N2`, and `N3` are the sizes of the arrays `S1`, `S2`, and `S3`, respectively. We traverse each array once in reverse order, perform constant-time operations, and iterate through the map `mp` to find the maximum sum.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N1 + N2 + N3)` as we use the unordered map `mp` to store the cumulative sums and their frequencies.

### Code (C++)

```cpp
class Solution{
public:
    int maxEqualSum(int N1, int N2, int N3, vector<int> &S1, vector<int> &S2, vector<int> &S3){
        unordered_map<int, int> mp;
        int s = 0;
        for(int i = N1 - 1; i >= 0; --i){
            s += S1[i];
            ++mp[s];
        }
        s = 0;
        for(int i = N2 - 1; i >= 0; --i){
            s += S2[i];
            if(mp.find(s) != mp.end())
                ++mp[s];
        }
        s = 0;
        for(int i = N3 - 1; i >= 0; --i){
            s += S3[i];
            if(mp.find(s) != mp.end())
                ++mp[s];
        }
        int out = 0;
        for(auto i: mp){
            if(i.second == 3){
                out = max(out, i.first);
            }
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.