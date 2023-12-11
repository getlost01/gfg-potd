## 11. Max Sum Subarray of size K
 The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
- Check if N is less than K, return -1 if true. This is to handle cases where the array size is smaller than the required subarray size.
- Initialize a variable sum to 0. Use a loop to calculate the sum of the first K elements of the array.
- Initialize a variable ans to the calculated sum.
- Use another loop starting from index K to N-1 to iterate through the array.
- Update the sum by subtracting the element at index i - K and adding the element at index i.
- Update ans by taking the maximum of the current ans and the updated sum.
- After the loop, return the final value of ans as the maximum sum of a subarray of size K.

### Time and Auxiliary Space Complexity

- **Time Complexity** : `O(N)`, where N is the size of the array.
- **Auxiliary Space Complexity** : `O(1)`

### Code (C++)
```cpp
class Solution{   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N)
    {
        if (N<K)
            return -1;
            
        long sum=0;
        for (int i=0;i<K;i++)
        {
            sum+=Arr[i];
        }
            
        long ans=sum;
        for (int i=K;i<N;i++)
        {
            sum+=Arr[i]-Arr[i-K];
            ans=max(ans, sum);
        }
        
        return ans;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.
