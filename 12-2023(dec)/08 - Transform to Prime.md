## 08. Transform to Prime
The problem can be found at the following link: [Question Link](https://www.geeksforgeeks.org/problems/transform-to-prime4635/1)

![](https://badgen.net/badge/Level/Medium/yellow)

### My Approach
Simple direct approach, I iterate through the array, calculate the sum of its elements, and check if the sum is a prime number. If it's not, I increment the sum until it becomes prime. The count of increments is the minimum number of operations needed to transform the array into a prime array.

### Time and Auxiliary Space Complexity

- **Time Complexity**: `O(N * sqrt(S))`, where `N` is the size of the array, and `S` is the sum of array elements.
- **Auxiliary Space Complexity**: `O(1)`, as no extra space is used.

### Code (C++)
```cpp
class Solution {
public:
    bool isprime(int& n) {
        if (n == 1) 
            return false;
            
        for (int i = 2; i <= sqrt(n); i++)
            if (n % i == 0) 
                return false;
                
        return true;
    }

    int minNumber(int arr[], int N) {
        int sum = 0;
        for (int i = 0; i < N; i++) 
            sum += arr[i];
            
        int cnt = 0;
        while (!isprime(sum)) {
            ++cnt;
            ++sum;
        }
            
        return cnt;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.