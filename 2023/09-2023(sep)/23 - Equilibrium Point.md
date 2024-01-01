## 23. Equilibrium Point
The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/equilibrium-point-1587115620/1)

### My Approach

Petty easy question.
- To find the equilibrium point, I calculate the total `sum` of the elements in the array. Then, 
- I iterate through the array and maintain a prefix sum `preSum` and subtract the current element from the total `sum`. 
	- If the remaining `sum == preSum` equals, I return the current index as the equilibrium point.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N)` where `N` is the number of elements in the array. We iterate through the array twice: once to calculate the total sum and once to find the equilibrium point.
- **Auxiliary Space Complexity**: `O(1)`. We only use a constant amount of extra space to store the `sum` and `preSum`.

### Code (C++)
```cpp
class Solution {
public:
    int equilibriumPoint(long long a[], int n) {
        long long sum = 0, preSum = 0;
        for(int i = 0; i < n; ++i)
            sum += a[i];
            
        for(int i = 0; i < n; ++i){
            sum -= a[i];
            if(sum == preSum)
                return i+1;
            preSum += a[i];
        }
        return -1;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.