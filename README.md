# GFG Problem Of The Day

## Today - 20 June 2023
### Que - Matchsticks game

[Question Link](https://practice.geeksforgeeks.org/problems/-matchsticks-game4906/1)


### My approach
- Observation based question, If the number `n` is a multiple of `5`, then `B` wins; otherwise, `A` will choose a number that is `n%5` to ensure his victory.


### Code (c++) 
```
class Solution {
  public:
    int matchGame(long long n) {
        if(n%5)
            return n%5;
        
        return -1;
    }
};
```

#### If you like my solutions, please consider a ⭐ `star` to this repo.

![GFG](https://komarev.com/ghpvc/?username=gl01potdgfg&color=blue&&label=Visitors)