## 05. Strictly Increasing Array
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/convert-to-strictly-increasing-array3351/1)

### My Approach
I'm using the Longest Increasing Subsequence (LIS) approach to solve this problem. 
- The LIS algorithm works by finding the length of the longest subsequence in a given array that is strictly increasing.
- I iterate through the array and maintain a dynamic programming array `dp`, where `dp[i]` represents the length of the LIS ending at index `i`.
- For each index `i`, I iterate over all previous indices `j` (0 to `i-1`), and if the element at index `i` is greater than the element at index `j`, and the difference between them is also greater than or equal to `i - j`, then I update `dp[i]` with the maximum of `1 + dp[j]` and `dp[i]`.
- Finally, I find the maximum value in the `dp` array, which represents the length of the LIS.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(n^2)`, where n is the size of the input array `nums`.
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(n)`, where n is the size of the input array `nums`. This is because we are using an additional dynamic programming array `dp` of size n.

### Code (C++)
```cpp
class Solution {
public:
    int lis(vector<int>& nums){
        int n = nums.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;++i)
            for(int j=0;j<i;j++)
                if(nums[i]>nums[j] && (nums[i]-nums[j])>=(i-j))
                    dp[i] = max(1+dp[j],dp[i]);
                    
        int out = 1;
        for(auto i: dp)
            out = max(out, i);
        
        return out;
    }
    int min_operations(vector<int>& nums) {
        return nums.size() - lis(nums);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.