## 24. Partitions with Given Difference
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1)

### My Approach
- Initialize DP Table: Create a 2D DP table t of size (n+1)x(sum1+1), where sum1 is the target sum derived from (sum + d) / 2.
- t[i][0] = 1 for all i, because there's one way to make sum 0 (by choosing no elements).
- t[0][j] = 0 for all j > 0, because with 0 elements, no positive sum can be formed.
- Iterate through each element in the array and update the DP table based on whether the current element can be included in the subset.
- If arr[i-1] <= j, update t[i][j] by adding the number of ways without including the element and the number of ways including the element.
- If arr[i-1] > j, simply carry forward the number of ways without including the element.
- The value at t[n][sum1] gives the count of subsets that meet the condition.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The time complexity of this approach is `O(N*sum1)`
- **Auxiliary Space Complexity**: The auxiliary space complexity is `O(N*sum1)`.

### Code (C++)

```cpp
class Solution {
  public:
    int count_no_of_subset(vector<int> &arr, int sum1, vector<vector<long long int>> &t)
    {
        for(int i=0;i<arr.size()+1;i++)
        {
            for(int j=0;j<sum1+1;j++)
            {
                if(i==0)
                    t[i][j]=0;
                if(j==0)
                    t[i][j]=1;
            }
        }
        
        long long int mod=1e9+7;
        
        for(int i=1;i<arr.size()+1;i++
        {
            for(int j=0;j<sum1+1;j++)
            {
                if(arr[i-1]<=j)
                    t[i][j]=((t[i-1][j])+(t[i-1][j-arr[i-1]]))%mod;
                else t[i][j]=(t[i-1][j]);
            }
        }
        
        return t[arr.size()][sum1];
    }
    
    int countPartitions(int n, int d, vector<int>& arr)
    {
        long long int sum=0;
        for(int i: arr)
            sum+=i;
        if((sum+d)%2!=0 || sum<d)
            return 0;
        long long int sum1=(sum+d)/2;
        sum1=min(sum1, sum - sum1);
        vector<vector<long long int>> t(n+1,vector<long long int>(sum1+1));
        return count_no_of_subset(arr,sum1,t);
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
