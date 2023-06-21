# GFG Problem Of The Day

## Today - 21 June 2023
### Que - Reverse Coding

[Question Link](https://practice.geeksforgeeks.org/problems/reverse-coding2452/1)


### My approach
- Simple question, just add all number by using this formula `(n*(n+1))/2`.


### Code (c++) 
```
class Solution {
  public:
    int mod = 1e9+7;
    int sumOfNaturals(int n) {
        long long sum = n;
        sum = (sum*(sum+1))%mod;
        sum /= 2;
        
        return sum;
    }
};
```

#### If you like my solutions, please consider a ⭐ `star` to this repo.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)