# GFG Problem Of The Day

## Today - 18 June 2023
### Que - Ticket Counter

[Question Link](https://practice.geeksforgeeks.org/problems/ticket-counter-2731/1)


### My approach
- This logic calculates the left and right boundaries of a given number `N` after performing a maximum of `OP` equal operations. If the difference between the `right` and `left` boundaries is greater than `k`, it outputs the leftmost value from the right boundary, which is essentially `left + k + 1`. By default, the output is the rightmost value from the `left` boundary until both operations have been performed an even number of times.

#### Time Complexity
`O(constant)` just we are doing comparisions

### Code (c++) 
```
class Solution {
  public:
        int distributeTicket(int n, int k) {
            int op = n/k;
            int left = (op/2)*k;
            int right = n - (op/2)*k + 1;
            
            if(right - left > (k + 1))
                return left + k + 1;
            
            return right - (right - left != 1);
        }
};
```

#### If you like my solutions, please consider ⭐ `star` this repo.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)