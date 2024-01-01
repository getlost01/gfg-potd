## 13. Nth Fibonacci Number

The problem can be found at the following link: [Question Link](https://practice.geeksforgeeks.org/problems/nth-fibonacci-number1335/1)

### My Approach

I use an iterative approach to calculate the nth Fibonacci number. I maintain two variables, `secondLast` and `last`, to keep track of the last two Fibonacci numbers. I iterate `n-1` times to calculate the nth Fibonacci number.

-  Initialize the 1st Fibonacci number to 0 using the variable `secondLast`, and the 2nd Fibonacci number to 1 using `last` variable.
- Proceed with a loop for the remaining `n-1` iterations, updating `curr` as the sum of `secondLast` and `last`. Subsequently, shift the value of `last` to `secondLast`, and assign the value of `curr` to `last` for the upcoming iterations.

### Explanation with Example

Let's take an example where `n` is 5.

```js
-  Iteration 1: secondLast = 0  ,  last = 1  ,  curr = (0 + 1) = 1
-  Iteration 2: secondLast = 1  ,  last = 1  ,  curr = (1 + 1) = 2
-  Iteration 3: secondLast = 1  ,  last = 2  ,  curr = (1 + 2) = 3
-  Iteration 4: secondLast = 2  ,  last = 3  ,  curr = (2 + 3) = 5
```
So, the 5th Fibonacci number is **5**.

### Time and Auxiliary Space Complexity

- **Time Complexity**: The loop runs for `n-1` iterations, resulting in a linear time complexity of `O(n)`.
- **Auxiliary Space Complexity**: The algorithm uses a constant amount of extra space, resulting in an auxiliary space complexity of `O(1)`.

### Code (C++)
```cpp
class Solution {
  public:
    int MOD = 1e9+7;
    int nthFibonacci(int n){
        int secondLast = 0;
        int last = 1;
        int curr = 1;
        
        n = n-1;
        while(n--){
            curr = (last + secondLast)%MOD;
            secondLast = last;
            last = curr;
        }
        
        return curr;
    }
};
```

### Contribution and Support

For discussions, questions, or doubts related to this solution, please visit our [discussion section](https://github.com/getlost01/gfg-potd/discussions). We welcome your input and aim to foster a collaborative learning environment.

If you find this solution helpful, consider supporting us by giving a ⭐ star to the [getlost01/gfg-potd](https://github.com/getlost01/gfg-potd) repository.