# GFG Problem Of The Day

## Today - 7 June 2023
### Que - Least Prime Factor

[Question Link](https://practice.geeksforgeeks.org/problems/least-prime-factor5216/1)

### My approach
- Simple brute force approach of finding prime number upto `sqrt(n)` .


### Code (c++)
```
class Solution {
  public:
    int findFactor(int n){
        if(n<2) return n;
        for(int i = 2;i<=sqrt(n);++i ){
            if(n%i == 0)
                return i;
        }
        return n;
    }
    
    vector<int> leastPrimeFactor(int n) {
        vector<int> out(n+1);
        for(int i = 0;i<=n;++i)
            out[i] = findFactor(i);
        return out;
    }
};
```