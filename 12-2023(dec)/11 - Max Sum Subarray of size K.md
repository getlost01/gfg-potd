## 11. Max Sum Subarray of size K
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/max-sum-subarray-of-size-k5313/1)

![](https://badgen.net/badge/Level/Easy/green)

### My Approach
Easy approach, I use a sliding window approach. I maintain a running sum of the current window and slide the window by subtracting the element that goes out of the window and adding the new element. I update the maximum sum at each step.

### Time and Auxiliary Space Complexity

- **Time Complexity**: O(N), where N is the size of the array.
- **Auxiliary Space Complexity**: O(1).

### Code (C++)
```cpp
class Solution {   
public:
    long maximumSumSubarray(int K, vector<int> &Arr , int N){
        long out = 0;
        long sum = 0;
        for(int i = 0; i < N ; ++i){
            sum += Arr[i];
            if(i >= K)
                sum -= Arr[i - K];
            
            out = max(out, sum);
        }
        return out;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a `⭐ star` to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.